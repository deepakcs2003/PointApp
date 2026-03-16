#pragma once
#include <QWidget>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QListWidget>
#include <QMap>
#include "BaseShape.h"
#include <Canvas.h>


class PropertyPanel : public QWidget {
    Q_OBJECT

public:
    PropertyPanel(Canvas* c,QWidget* parent = nullptr);
	static int id; 

public slots:
    void loadShape(BaseShape* shape,QString shapeName);
    void onShapeAdded(BaseShape* shape);

private slots:
    void onPosXChanged(double v);
    void onPosYChanged(double v);
    void onPosZChanged(double v);

    void onScaleChanged(double v);

    void onRotXChanged(double v);
    void onRotYChanged(double v);
    void onRotZChanged(double v);

    void onColorChanged(const QString& colorName);
    void onVisibilityToggled(bool checked);
    void updateMeasurements();
    void onShapeListItemSelected(QListWidgetItem* item);
    void onLockedToggled(bool checked);
  
private:
    BaseShape* currentShape = nullptr;
    int shapeCounter = 0;  // Counter to make unique shape identifiers

    QLabel* titleLabel;

    QDoubleSpinBox* scaleBox;
    QDoubleSpinBox* posX;
    QDoubleSpinBox* posY;
    QDoubleSpinBox* posZ;

    QDoubleSpinBox* RposX;
    QDoubleSpinBox* RposY;
    QDoubleSpinBox* RposZ;

    QLineEdit* surfaceAreaField;
    QLineEdit* volumeField;

    QComboBox* colorCombo;

    QPushButton* visibleBtn;
    QPushButton* lockedBtn;
    void setControlsEnabled(bool enabled);// helper to enable/disable all inputs

    QListWidget* shapeList;

    Canvas* canvas;
};