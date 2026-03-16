#include "PropertyPanel.h"
#include <QFormLayout>
#include <QtMath>

PropertyPanel::PropertyPanel(QWidget* parent) : QWidget(parent) {
    QFormLayout* form = new QFormLayout(this);
    form->setVerticalSpacing(8);

    titleLabel = new QLabel("<b>Select a Shape</b>");

    titleLabel->setAlignment(Qt::AlignCenter);
    form->addRow(titleLabel);

    shapeList = new QListWidget();
    shapeList->setMaximumHeight(120);

    form->addRow(shapeList);


    scaleBox = new QDoubleSpinBox();

    posX = new QDoubleSpinBox();
    posY = new QDoubleSpinBox();
    posZ = new QDoubleSpinBox();

    RposX = new QDoubleSpinBox();
    RposY = new QDoubleSpinBox();
    RposZ = new QDoubleSpinBox();

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

    connect(posX, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this, &PropertyPanel::onPosXChanged);

    connect(posY, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this, &PropertyPanel::onPosYChanged);

    connect(posZ, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this, &PropertyPanel::onPosZChanged);

    connect(scaleBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this, &PropertyPanel::onScaleChanged);

    connect(RposX, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this, &PropertyPanel::onRotXChanged);

    connect(RposY, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this, &PropertyPanel::onRotYChanged);

    connect(RposZ, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this, &PropertyPanel::onRotZChanged);

    connect(colorCombo, &QComboBox::currentTextChanged,
        this, &PropertyPanel::onColorChanged);

    connect(visibleBtn, &QPushButton::toggled,
        this, &PropertyPanel::onVisibilityToggled);

    connect(lockedBtn, &QPushButton::toggled,
        this, &PropertyPanel::onLockedToggled);
    connect(posX, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this, &PropertyPanel::updateMeasurements);

    connect(posY, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this, &PropertyPanel::updateMeasurements);

    connect(posZ, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this, &PropertyPanel::updateMeasurements);

    connect(scaleBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
        this, &PropertyPanel::updateMeasurements);

}

void PropertyPanel::loadShape(BaseShape* shape)
{
    if (!shape) return;

    currentShape = shape;

    QString name = shape->shapeName();

    titleLabel->setText("Active: " + name);

    if (shapeList->findItems(name, Qt::MatchExactly).isEmpty())
    {
        shapeList->addItem(name);
    }

    posX->setValue(shape->position().x());
    posY->setValue(shape->position().y());
    posZ->setValue(shape->position().z());

    scaleBox->setValue(shape->scale());

    RposX->setValue(shape->rotX());
    RposY->setValue(shape->rotY());
    RposZ->setValue(shape->rotZ());

    setControlsEnabled(!lockedBtn->isChecked());

    updateMeasurements();
}


void PropertyPanel::updateMeasurements()
{
    if (!currentShape) return;

    float area = 0.0f;
    float volume = 0.0f;
    float pi = 3.1416f;
    float scale = scaleBox->value(); // take scale input from form

    QString name = currentShape->shapeName();

    if (name == "Cone") {
        float r = 1.5f * scale;
        float h = 4.0f * scale;
        float l = sqrt(r * r + h * h);
        area = pi * r * (r + l);
        volume = (pi * r * r * h) / 3.0f;
    }
    else if (name == "Cylinder") {
        float r = 1.0f * scale;
        float h = 4.0f * scale;
        area = 2 * pi * r * (r + h);
        volume = pi * r * r * h;
    }
    else if (name == "Sphere") {
        float r = 1.5f * scale;
        area = 4 * pi * r * r;
        volume = (4.0f / 3.0f) * pi * r * r * r;
    }
    else if (name == "Cuboid") {
        float l = 2.0f * scale;
        float w = 3.0f * scale;
        float h = 4.0f * scale;
        area = 2 * (l * w + l * h + w * h);
        volume = l * w * h;
    }

    surfaceAreaField->setText(QString::number(area, 'f', 2));
    volumeField->setText(QString::number(volume, 'f', 2));
}

void PropertyPanel::onPosXChanged(double v)
{
    if (currentShape)
        currentShape->setPositionX(v);
}

void PropertyPanel::onPosYChanged(double v)
{
    if (currentShape)
        currentShape->setPositionY(v);
}

void PropertyPanel::onPosZChanged(double v)
{
    if (currentShape)
        currentShape->setPositionZ(v);
}

void PropertyPanel::onScaleChanged(double v)
{
    if (currentShape)
        currentShape->setScale(v);
}

void PropertyPanel::onRotXChanged(double v)
{
    if (currentShape)
        currentShape->setRotationX(v);
}

void PropertyPanel::onRotYChanged(double v)
{
    if (currentShape)
        currentShape->setRotationY(v);
}

void PropertyPanel::onRotZChanged(double v)
{
    if (currentShape)
        currentShape->setRotationZ(v);
}

void PropertyPanel::onColorChanged(const QString& colorName)
{
    if (currentShape)
        currentShape->setColor(colorName);
}

void PropertyPanel::onVisibilityToggled(bool checked)
{
    if (currentShape)
        currentShape->setVisible(checked);
}
void PropertyPanel::onLockedToggled(bool checked)
{
    setControlsEnabled(!checked);  // disable controls when locked

    // Update button appearance to give visual feedback
    if (checked)
        lockedBtn->setText("🔒 Locked");
    else
        lockedBtn->setText("Unlocked");
}

void PropertyPanel::setControlsEnabled(bool enabled)
{
    posX->setEnabled(enabled);
    posY->setEnabled(enabled);
    posZ->setEnabled(enabled);
    scaleBox->setEnabled(enabled);
    RposX->setEnabled(enabled);
    RposY->setEnabled(enabled);
    RposZ->setEnabled(enabled);
    colorCombo->setEnabled(enabled);
    visibleBtn->setEnabled(enabled);
}