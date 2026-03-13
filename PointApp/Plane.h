#pragma once
#include <QObject>

#include <Qt3DCore/QTransform>
#include <Qt3DCore/QEntity>

#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QPhongMaterial>
class Plane:QObject
{
    Q_OBJECT
        
public:
    Plane(Qt3DCore::QEntity* rootEntity);
    ~Plane();
public slots:
    void enablePlane(bool enabled);

private:
    Qt3DCore::QEntity* m_rootEntity;
    Qt3DCore::QEntity* m_planeEntity;
};
