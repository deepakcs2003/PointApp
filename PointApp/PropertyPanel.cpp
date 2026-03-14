#include "PropertyPanel.h"
#include <QFormLayout>
#include <QtMath>

PropertyPanel::PropertyPanel(QWidget* parent) : QWidget(parent) {
    QFormLayout* form = new QFormLayout(this);
    form->setVerticalSpacing(8);

    titleLabel = new QLabel("<b>Select a Shape</b>");
    titleLabel->setAlignment(Qt::AlignCenter);
    form->addRow(titleLabel);

    scaleBox = new QDoubleSpinBox(); 
   
    posX = new QDoubleSpinBox();
    posY = new QDoubleSpinBox(); 
    posZ = new QDoubleSpinBox();

    RposX = new QDoubleSpinBox(); 
    RposY = new QDoubleSpinBox();
    RposZ = new QDoubleSpinBox();

    posX->setRange(-1000.0, 1000.0);
    posY->setRange(-1000.0, 1000.0);
    posZ->setRange(-1000.0, 1000.0);
    scaleBox->setRange(-1000.0, 1000.0); 
    RposX->setRange(-360.0, 360.0);
    RposY->setRange(-360.0, 360.0);
    RposZ->setRange(-360.0, 360.0);


    surfaceAreaField = new QLineEdit("0.0");
    surfaceAreaField->setReadOnly(true);
    volumeField = new QLineEdit("0.0");
    volumeField->setReadOnly(true);

    colorCombo = new QComboBox();
    colorCombo->addItems({ "Blue", "Red", "Green", "Yellow", "White", "Black" });

    visibleBtn = new QPushButton("Visible");
    visibleBtn->setCheckable(true);
    visibleBtn->setChecked(true); 

    lockedBtn = new QPushButton("Locked");
    lockedBtn->setCheckable(true);

    form->addRow(new QLabel("<br><b>Positions</b>"));
    form->addRow("Scale:", scaleBox);
    form->addRow("X:", posX);
    form->addRow("Y:", posY);
    form->addRow("Z:", posZ);

    form->addRow(new QLabel("<br><b>Rotations</b>"));
    form->addRow("RX:", RposX);
    form->addRow("RY:", RposY);
    form->addRow("RZ:", RposZ);


    form->addRow(new QLabel("<br><b>Appearance</b>"));
    form->addRow("Color:", colorCombo);

    form->addRow(new QLabel("<b>State</b>"));
    form->addRow(visibleBtn);
    form->addRow(lockedBtn);

    form->addRow(new QLabel("<br><b>Measurements</b>"));
    form->addRow("Area:", surfaceAreaField);
    form->addRow("Vol:", volumeField);

    setFixedWidth(200);


}

void PropertyPanel::updateName(QString name) {
   
    if (name == "Cuboid" || name == "Sphere" ||
        name == "Rectangle" || name == "Cyl"||name=="Line")
    {
        titleLabel->setText("<b>Active: " + name + "</b>");
    }
    //calculateSurfaceArea();
    //calculateVolume();
}



void PropertyPanel::setValue(QString shape, float x, float y, float z, float p1)
{
    posX->setValue(x);
    posY->setValue(y);
    posZ->setValue(z);

    if (shape == "Cuboid")
    {
        scaleBox->setValue(p1);      
        scaleBox->setSuffix(" (Scale)");
    }
    else if (shape == "Sphere")
    {
        scaleBox->setValue(p1);     
        scaleBox->setSuffix(" (Radius)");
    }
    else if (shape == "Cylinder")
    {
        scaleBox->setValue(p1);     
    }

    calculateSurfaceArea(shape, x, y, z, p1);
    calculateVolume(shape, x, y, z, p1);
}   

void PropertyPanel::calculateSurfaceArea(QString shape, float x, float y, float z, float p1)
{
    double area = 0.0;
    if (shape == "Cuboid") {
        area = 2.0 * (x * y + y * z + x * z); 
    }
    else if (shape == "Sphere") {
        area = 4.0 * M_PI * p1 * p1; 
    }
    else if (shape == "Cylinder") {
        area = 2.0 * M_PI * p1 * (p1 + z);
    }

    surfaceAreaField->setText(QString::number(area, 'f', 2));
}

void PropertyPanel::calculateVolume(QString shape, float x, float y, float z, float p1)
{
    double volume = 0.0;
    if (shape == "Cuboid") {
        volume = x * y * z;
    }
    else if (shape == "Sphere") {
        volume = (4.0 / 3.0) * M_PI * p1 * p1 * p1;
    }
    else if (shape == "Cylinder") {
        volume = M_PI * p1 * p1 * z; 
    }

    volumeField->setText(QString::number(volume, 'f', 2));
}