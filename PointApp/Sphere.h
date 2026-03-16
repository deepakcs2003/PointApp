#pragma once
#include <QObject>

#include "BaseShape.h"

#include <Qt3DExtras/QSphereMesh>

class Sphere : public BaseShape
{
	Q_OBJECT
public:
    Sphere(Qt3DCore::QEntity* rootEntity);
    ~Sphere();
    QString shapeName() const override;

};

