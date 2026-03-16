#include "Cuboid.h"

#include <Qt3DRender/QGeometryRenderer>

#include <QtGui/QQuaternion>

#include <QtCore/QDebug>

Cuboid::Cuboid(Qt3DCore::QEntity* rootEntity) :BaseShape(rootEntity)
{
    Qt3DExtras::QCuboidMesh* cubeMesh = new Qt3DExtras::QCuboidMesh();

    cubeMesh->setXExtent(3);
    cubeMesh->setYExtent(3);
    cubeMesh->setZExtent(3);

    // Transform
    m_transform = new Qt3DCore::QTransform();
    m_transform->setScale(1.0f);
    m_transform->setTranslation(QVector3D(0, 0, 0));

    // Material
    m_material = new Qt3DExtras::QPhongMaterial();
    m_material->setDiffuse(QColor(QRgb(0x928327)));

    // Entity
    m_entity = new Qt3DCore::QEntity(m_rootEntity);

    m_entity->addComponent(cubeMesh);
    m_entity->addComponent(m_transform);
    m_entity->addComponent(m_material);
    
}

Cuboid::~Cuboid()
{
}
void Cuboid::enableCuboid(bool enabled)
{
    if (m_entity)
        m_entity->setEnabled(enabled);
}

QString Cuboid::shapeName() const
{
    return "Cuboid";
}