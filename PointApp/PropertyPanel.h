#pragma once
#include <QWidget>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QListWidget>
#include "BaseShape.h"

class PropertyPanel : public QWidget {
    Q_OBJECT

public:
    explicit PropertyPanel(QWidget* parent = nullptr);

public slots:
    void loadShape(BaseShape* shape);

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
    void onLockedToggled(bool checked);

    void  updateMeasurements();
private:
    BaseShape* currentShape = nullptr;

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

};