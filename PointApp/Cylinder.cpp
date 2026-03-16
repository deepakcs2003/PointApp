#include "Cylinder.h"
#include <Qt3DRender/QGeometryRenderer>

#include <QtGui/QQuaternion>

#include <QtCore/QDebug>

Cylinder::Cylinder(Qt3DCore::QEntity* rootEntity) :m_rootEntity(rootEntity) {
    // Cylinder shape data
    Qt3DExtras::QCylinderMesh* cylinder = new Qt3DExtras::QCylinderMesh();
    cylinder->setRadius(1);
    cylinder->setLength(3);
    cylinder->setRings(100);
    cylinder->setSlices(20);

    // CylinderMesh Transform
    Qt3DCore::QTransform* cylinderTransform = new Qt3DCore::QTransform();
    cylinderTransform->setScale(1.5f);
    cylinderTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 45.0f));
    cylinderTransform->setTranslation(QVector3D(-5.0f, 4.0f, -1.5));

    Qt3DExtras::QPhongMaterial* cylinderMaterial = new Qt3DExtras::QPhongMaterial();
    cylinderMaterial->setDiffuse(QColor(QRgb(0x928327)));


    // Cylinder
    {
        m_cylinderEntity = new Qt3DCore::QEntity(m_rootEntity);
        m_cylinderEntity->addComponent(cylinder);
        m_cylinderEntity->addComponent(cylinderMaterial);
        m_cylinderEntity->addComponent(cylinderTransform);
    }

}
Cylinder::~Cylinder()
{
}

void Cylinder::enableCylinder(bool enabled) {

}