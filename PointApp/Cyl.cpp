#include <QColor>
#include "Cyl.h"

Cylinder::Cylinder(Qt3DCore::QEntity* rootEntity) : BaseShape(rootEntity)
{
    // 1️⃣ Create cylinder mesh
    Qt3DExtras::QCylinderMesh* cylinderMesh = new Qt3DExtras::QCylinderMesh();
    cylinderMesh->setRadius(1.0f);
    cylinderMesh->setLength(4.0f);
    cylinderMesh->setRings(50);
    cylinderMesh->setSlices(20);

    m_transform = new Qt3DCore::QTransform();
    m_transform->setScale(1.0f);
    m_transform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    m_material = new Qt3DExtras::QPhongMaterial();
    m_material->setDiffuse(QColor(100, 200, 150));

    // 4️⃣ Create entity andadd components
    m_entity = new Qt3DCore::QEntity(rootEntity);
    m_entity->addComponent(cylinderMesh);
    m_entity->addComponent(m_transform);
    m_entity->addComponent(m_material);
}

Cylinder::~Cylinder()
{
}

QString Cylinder::shapeName() const
{
    return "Cylinder";
}

//void Cylinder::enableCylinder(bool enabled)
//{
//    if (m_entity)
//        m_entity->setEnabled(enabled);
//}