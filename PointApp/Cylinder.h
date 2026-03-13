#pragma once
#include <QObject>

#include <Qt3DCore/QTransform>
#include <Qt3DCore/QEntity>

#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QPhongMaterial>
class Cylinder :public QObject
{
    Q_OBJECT
public:
    Cylinder(Qt3DCore::QEntity* rootEntity);
    ~Cylinder();
public slots:
    void enableCylinder(bool enabled);

private:
    Qt3DCore::QEntity* m_rootEntity;
    Qt3DCore::QEntity* m_cylinderEntity;
    Qt3DExtras::QCylinderMesh* m_cylinder;

};


