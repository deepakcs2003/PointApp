#pragma once

#include <QObject>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>

#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPhongMaterial>
#include<PropertyPanel.h>

class Cuboid : public QObject
{
    Q_OBJECT

public:
    Cuboid(Qt3DCore::QEntity* rootEntity, PropertyPanel* panel);
    ~Cuboid();

public slots:
    void enableCuboid(bool enabled);

private:
    Qt3DCore::QEntity* m_rootEntity;
    Qt3DCore::QEntity* m_cuboidEntity;
    PropertyPanel* p;

signals:
    //void cuboidCreated(float x, float y, float z, float scale);
};