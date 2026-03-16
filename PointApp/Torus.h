#pragma once
#include <QObject>

#include <Qt3DCore/QTransform>
#include <Qt3DCore/QEntity>

#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QPhongMaterial>
class Torus :public QObject
{
    Q_OBJECT
public:
    Torus(Qt3DCore::QEntity* rootEntity);
    ~Torus();
public slots:
    void enableTorus(bool enabled);

private:
    Qt3DCore::QEntity* m_rootEntity;
    Qt3DCore::QEntity* m_torusEntity;
    Qt3DExtras::QTorusMesh* m_torus;
};


