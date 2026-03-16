
#include "BaseShape.h"

BaseShape::BaseShape(Qt3DCore::QEntity* rootEntity): m_rootEntity(rootEntity)
{

}

BaseShape::~BaseShape()
{
}

void BaseShape::setPositionX(double x)
{
    if (!m_transform) return;

    QVector3D pos = m_transform->translation();
    pos.setX(x);
    m_transform->setTranslation(pos);

}

void BaseShape::setPositionY(double y)
{
    if (!m_transform) return;

    QVector3D pos = m_transform->translation();
    pos.setY(y);
    m_transform->setTranslation(pos);
}

void BaseShape::setPositionZ(double z)
{
    if (!m_transform) return;

    QVector3D pos = m_transform->translation();
    pos.setZ(z);
    m_transform->setTranslation(pos);
}

void BaseShape::setScale(double s)
{
    if (m_transform)
        m_transform->setScale(static_cast<float>(s));
}

void BaseShape::setRotationX(double rx)
{
    if (m_transform)
        m_transform->setRotationY(static_cast<float>(rx));
}

void BaseShape::setRotationY(double ry)
{
    if (m_transform)
        m_transform->setRotationX(static_cast<float>(ry));
}

void BaseShape::setRotationZ(double rz)
{
    if (m_transform)
        m_transform->setRotationZ(static_cast<float>(rz));
}

void BaseShape::setColor(const QString& colorName)
{
    QColor color(colorName);

    if (color.isValid() && m_material)
        m_material->setDiffuse(color);
}

void BaseShape::setVisible(bool visible)
{
    if (m_entity)
        m_entity->setEnabled(visible);
}

QVector3D BaseShape::position() const
{
    return m_transform ? m_transform->translation() : QVector3D();
}

float BaseShape::scale() const
{
    return m_transform ? m_transform->scale() : 1.0f;
}

float BaseShape::rotX() const
{
    return m_transform ? m_transform->rotationX() : 0.0f;
}

float BaseShape::rotY() const
{
    return m_transform ? m_transform->rotationY() : 0.0f;
}

float BaseShape::rotZ() const
{
    return m_transform ? m_transform->rotationZ() : 0.0f;
}

QColor BaseShape::color() const
{
    return m_material ? m_material->diffuse() : QColor(Qt::white);
}
