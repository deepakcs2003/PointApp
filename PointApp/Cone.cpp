#include "Cone.h"
#include <QColor>

Cone::Cone(Qt3DCore::QEntity* rootEntity) : BaseShape(rootEntity)
{
    Qt3DExtras::QConeMesh* coneMesh = new Qt3DExtras::QConeMesh();
    coneMesh->setTopRadius(0.01f);   
    coneMesh->setBottomRadius(1.5f);
    coneMesh->setLength(4.0f);
    coneMesh->setRings(50);
    coneMesh->setSlices(20);

    m_transform = new Qt3DCore::QTransform();
    m_transform->setScale(1.0f);
    m_transform->setTranslation(QVector3D(6.0f, 0.0f, 0.0f));

    m_material = new Qt3DExtras::QPhongMaterial();
    m_material->setDiffuse(QColor(200, 120, 40));

    m_entity = new Qt3DCore::QEntity(rootEntity);
    m_entity->addComponent(coneMesh);
    m_entity->addComponent(m_transform);
    m_entity->addComponent(m_material);
}

Cone::~Cone()
{
}

QString Cone::shapeName() const
{
    return "Cone";
}

void Cone::enableCone(bool enabled)
{
    if (m_entity)
        m_entity->setEnabled(enabled);
}