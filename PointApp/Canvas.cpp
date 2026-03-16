#include "Canvas.h"
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QScreen>
#include <Cuboid.h>
#include <Sphere.h>


#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <QPainter>
#include <Sphere.h>
#include "Cone.h"
#include "Cyl.h"

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
    m_camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);

    m_camController->setCamera(camera);
    view->installEventFilter(this);
}

Canvas::~Canvas()
{
}



void Canvas::onToolSelected(QString toolName)
{
    m_activeTool = toolName;

    if (toolName == "Move" || toolName == "Rot" || toolName == "Scale") {
        if (m_camController) m_camController->setEnabled(false);
        return;
    }
    else {
        if (m_camController) m_camController->setEnabled(true);
    }

    if (shapes.contains(toolName)) {
        BaseShape* existing = shapes[toolName];
        existing->setVisible(true);
        m_activeShape = existing;
        emit shapeAdded(existing);
        return;
    }
    BaseShape* newShape = nullptr;
    if (toolName == "Sphere") {
        newShape = new Sphere(rootEntity);
    }
    if (toolName == "Cuboid")
    {
        newShape = new Cuboid(rootEntity);
    }
    if (toolName == "Cone") {
        newShape = new Cone(rootEntity);
    }
    if (toolName == "Cyl")
    {
        newShape = new Cylinder(rootEntity);
    }
    if (newShape) {
        shapes[toolName] = newShape;
        m_activeShape = newShape;
        emit shapeAdded(newShape);
    }
}

bool Canvas::eventFilter(QObject* obj, QEvent* ev)
{
    if (obj == view && m_activeShape) {
        if (ev->type() == QEvent::MouseButtonPress) {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(ev);
            m_lastMousePos = mouseEvent->pos();
            if (m_activeTool == "Move" || m_activeTool == "Rot" || m_activeTool == "Scale") {
                return true;
            }
        }
        else if (ev->type() == QEvent::MouseMove) {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(ev);
            if (mouseEvent->buttons() & Qt::LeftButton) {
                QPoint delta = mouseEvent->pos() - m_lastMousePos;
                m_lastMousePos = mouseEvent->pos();

                if (m_activeTool == "Move") {
                    m_activeShape->setPositionX(m_activeShape->position().x() + delta.x() * 0.1f);
                    m_activeShape->setPositionY(m_activeShape->position().y() - delta.y() * 0.1f);
                    emit shapeAdded(m_activeShape);
                    return true;
                }
                else if (m_activeTool == "Rot") {
                    m_activeShape->setRotationY(m_activeShape->rotY() + delta.x());
                    m_activeShape->setRotationX(m_activeShape->rotX() + delta.y());
                    emit shapeAdded(m_activeShape);
                    return true;
                }
                else if (m_activeTool == "Scale") {
                    float s = m_activeShape->scale() + ((delta.y() < 0 || delta.x() > 0) ? 0.05f : -0.05f);
                    if (s < 0.1f) s = 0.1f;
                    m_activeShape->setScale(s);
                    emit shapeAdded(m_activeShape);
                    return true;
                }
            }
        }
    }
    return QWidget::eventFilter(obj, ev);
}


