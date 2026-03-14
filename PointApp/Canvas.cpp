#include "Canvas.h"
#include <QVBoxLayout>
#include <QScreen>

#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <QPainter>
#include<PropertyPanel.h>


Canvas::Canvas(QWidget* parent) : QWidget(parent)
{

    view = new Qt3DExtras::Qt3DWindow();

    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));

    container = QWidget::createWindowContainer(view);

    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(container, 1);      


    setLayout(layout);

    // Root entity
    rootEntity = new Qt3DCore::QEntity();
    view->setRootEntity(rootEntity);

    // cuboid initially null
    cuboid = nullptr;
    propertyPanel = nullptr;


    // Camera
    Qt3DRender::QCamera* camera = view->camera();

    camera->lens()->setPerspectiveProjection(
        45.0f,
        16.0f / 9.0f,
        0.1f,
        1000.0f
    );

    camera->setPosition(QVector3D(0, 0, 20));
    camera->setViewCenter(QVector3D(0, 0, 0));

    // camera controller
    Qt3DExtras::QFirstPersonCameraController* camController =
        new Qt3DExtras::QFirstPersonCameraController(rootEntity);

    camController->setCamera(camera);
}

Canvas::~Canvas()
{
}

void Canvas::setPropertyPanel(PropertyPanel* panel)
{
    propertyPanel = panel;
}


void Canvas::showTool(QString tool)
{
    if (tool == "Cuboid")
    {
        if (!cuboid)
        {
            cuboid = new Cuboid(rootEntity, propertyPanel);
          
        }

        cuboid->enableCuboid(true);
        
    }
    else if (tool == "Sphere") {
        if (!sphere) {
            sphere = new Sphere(rootEntity, propertyPanel);
        }
        sphere->enableSphere(true);
    }
}


