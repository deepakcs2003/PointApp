#pragma once

#include <QObject>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QPhongMaterial>
#include "BaseShape.h"

class Cylinder : public BaseShape
{
    Q_OBJECT
public:
    Cylinder(Qt3DCore::QEntity* rootEntity);
    ~Cylinder();

    QString shapeName() const override;

//public slots:
//    void enableCylinder(bool enabled);
};