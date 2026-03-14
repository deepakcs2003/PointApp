#pragma once
#include <QObject>

#include <Qt3DCore/QTransform>
#include <Qt3DCore/QEntity>

#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QPhongMaterial>
#include<PropertyPanel.h>
class Sphere : public QObject
{
	Q_OBJECT
public:
    Sphere(Qt3DCore::QEntity* rootEntity,PropertyPanel*p);
    ~Sphere();
public slots:
    void enableSphere(bool enabled);

private:
    Qt3DCore::QEntity* m_rootEntity;
    Qt3DCore::QEntity* m_sphereEntity;
    PropertyPanel* p;

};

