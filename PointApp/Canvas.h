#pragma once
#include <Sphere.h>
#include <QWidget>
#include <Cuboid.h>
#include <PropertyPanel.h>
#include <Qt3DExtras/qt3dwindow.h>

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget* parent = nullptr);
    ~Canvas();

public slots:
    void showTool(QString tool);
    void setPropertyPanel(PropertyPanel* panel);

private:

    Qt3DExtras::Qt3DWindow* view;
    QWidget* container;

    Qt3DCore::QEntity* rootEntity;

    Cuboid* cuboid;
    Sphere* sphere;
    PropertyPanel* propertyPanel;
};

