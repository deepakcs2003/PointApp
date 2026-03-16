#include "Sphere.h"

#include <Qt3DRender/QGeometryRenderer>

#include <QtGui/QQuaternion>

#include <QtCore/QDebug>


Sphere::Sphere(Qt3DCore::QEntity* rootEntity):BaseShape(rootEntity)
{
    // Sphere shape data
    Qt3DExtras::QSphereMesh* sphereMesh = new Qt3DExtras::QSphereMesh();
    sphereMesh->setRings(20);
    sphereMesh->setSlices(20);
    sphereMesh->setRadius(2);

    // Sphere mesh transform
    m_transform= new Qt3DCore::QTransform();

    m_transform->setScale(1.3f);
    m_transform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));
    //m_transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0, 1, 0), 45));

    // Sphere mesh Material
    m_material = new Qt3DExtras::QPhongMaterial();
    m_material->setDiffuse(QColor(QRgb(0xa69929)));

    // Sphere
    m_entity = new Qt3DCore::QEntity(m_rootEntity);
    m_entity->addComponent(sphereMesh);
    m_entity->addComponent(m_transform);
    m_entity->addComponent(m_material);
    
}

Sphere::~Sphere()
{
}

QString Sphere::shapeName() const
{
    return "Sphere";
}

