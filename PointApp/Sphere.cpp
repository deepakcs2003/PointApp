#include "Sphere.h"

#include <Qt3DRender/QGeometryRenderer>

#include <QtGui/QQuaternion>

#include <QtCore/QDebug>
#include<PropertyPanel.h>


Sphere::Sphere(Qt3DCore::QEntity* rootEntity,PropertyPanel*panel):m_rootEntity(rootEntity), p(panel)
{
    // Sphere shape data
    Qt3DExtras::QSphereMesh* sphereMesh = new Qt3DExtras::QSphereMesh();
    sphereMesh->setRings(20);
    sphereMesh->setSlices(20);
    sphereMesh->setRadius(2);

    // Sphere mesh transform
    Qt3DCore::QTransform* sphereTransform = new Qt3DCore::QTransform();

    sphereTransform->setScale(1.3f);
    sphereTransform->setTranslation(QVector3D(-5.0f, -4.0f, 0.0f));

    Qt3DExtras::QPhongMaterial* sphereMaterial = new Qt3DExtras::QPhongMaterial();
    sphereMaterial->setDiffuse(QColor(QRgb(0xa69929)));

    // Sphere
   
    m_sphereEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_sphereEntity->addComponent(sphereMesh);
    m_sphereEntity->addComponent(sphereMaterial);
    m_sphereEntity->addComponent(sphereTransform);

    if (p)
    {
        p->setValue("Sphere", -5.0f, -4.0f, 0.0f, 2.0f);
    }
}

Sphere::~Sphere()
{
}


void Sphere::enableSphere(bool enabled) {
    m_sphereEntity->setEnabled(enabled);
};
