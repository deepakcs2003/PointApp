#pragma once
#include <QObject>

#include <Qt3DCore/QTransform>
#include <Qt3DCore/QEntity>

#include <Qt3DExtras/QConeMesh>
#include <Qt3DExtras/QPhongMaterial>
class Cone : public QObject
{
    Q_OBJECT
public:
    Cone(Qt3DCore::QEntity* rootEntity);
    ~Cone();
public slots:
    void enableCone(bool enabled);

private:
    Qt3DCore::QEntity* m_rootEntity;
    Qt3DCore::QEntity* m_coneEntity;
};

