#include "Cone.h"

#include <Qt3DRender/QGeometryRenderer>

#include <QtGui/QQuaternion>

#include <QtCore/QDebug>

Cone::Cone(Qt3DCore::QEntity* rootEntity) :m_rootEntity(rootEntity)
{
    // Cone shape data
    Qt3DExtras::QConeMesh* cone = new Qt3DExtras::QConeMesh();
    cone->setTopRadius(0.5);
    cone->setBottomRadius(1);
    cone->setLength(3);
    cone->setRings(50);
    cone->setSlices(20);

    // ConeMesh Transform
    Qt3DCore::QTransform* coneTransform = new Qt3DCore::QTransform();
    coneTransform->setScale(1.5f);
    coneTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 45.0f));
    coneTransform->setTranslation(QVector3D(0.0f, 4.0f, -1.5));

    Qt3DExtras::QPhongMaterial* coneMaterial = new Qt3DExtras::QPhongMaterial();
    coneMaterial->setDiffuse(QColor(QRgb(0x928327)));

    // Cone
    {
        m_coneEntity = new Qt3DCore::QEntity(m_rootEntity);
        m_coneEntity->addComponent(cone);
        m_coneEntity->addComponent(coneMaterial);
        m_coneEntity->addComponent(coneTransform);
    }
}

Cone::~Cone()
{
}


void Cone::enableCone(bool enabled) {
    m_coneEntity->setEnabled(true);
}

