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

class PropertyPanel : public QWidget {
    Q_OBJECT

public:
    explicit PropertyPanel(QWidget* parent = nullptr);

public slots:
    void loadShape(BaseShape* shape);
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

private:
    BaseShape* currentShape = nullptr;
    QMap<QString, BaseShape*> shapeMap;  // Map to store shape pointers by name
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

    QListWidget* shapeList;
};