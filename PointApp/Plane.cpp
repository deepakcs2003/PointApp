#include "Plane.h"

#include <Qt3DRender/QGeometryRenderer>

#include <QtGui/QQuaternion>

#include <QtCore/QDebug>

Plane::Plane(Qt3DCore::QEntity* rootEntity)
{
    // Plane shape data
    Qt3DExtras::QPlaneMesh* planeMesh = new Qt3DExtras::QPlaneMesh();
    planeMesh->setWidth(2);
    planeMesh->setHeight(2);

    // Plane mesh transform
    Qt3DCore::QTransform* planeTransform = new Qt3DCore::QTransform();
    planeTransform->setScale(1.3f);
    planeTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 45.0f));
    planeTransform->setTranslation(QVector3D(0.0f, -4.0f, 0.0f));

    Qt3DExtras::QPhongMaterial* planeMaterial = new Qt3DExtras::QPhongMaterial();
    planeMaterial->setDiffuse(QColor(QRgb(0xa69929)));

    // Plane
    {
        m_planeEntity = new Qt3DCore::QEntity(m_rootEntity);
        m_planeEntity->addComponent(planeMesh);
        m_planeEntity->addComponent(planeMaterial);
        m_planeEntity->addComponent(planeTransform);
    }
}

Plane::~Plane()
{
}

void Plane::enablePlane(bool enabled) {

}
