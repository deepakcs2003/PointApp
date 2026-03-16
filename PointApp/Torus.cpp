#include "Torus.h"
#include <Qt3DRender/QGeometryRenderer>

#include <QtGui/QQuaternion>

#include <QtCore/QDebug>


Torus::Torus(Qt3DCore::QEntity* rootEntity) :m_rootEntity(rootEntity)
{ // Torus shape data
    //! [0]
    m_torus = new Qt3DExtras::QTorusMesh();
    m_torus->setRadius(1.0f);
    m_torus->setMinorRadius(0.4f);
    m_torus->setRings(100);
    m_torus->setSlices(20);
    //! [0]

    // TorusMesh Transform
    //! [1]
    Qt3DCore::QTransform* torusTransform = new Qt3DCore::QTransform();
    torusTransform->setScale(2.0f);
    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 25.0f));
    torusTransform->setTranslation(QVector3D(5.0f, 4.0f, 0.0f));
    //! [1]

    //! [2]
    Qt3DExtras::QPhongMaterial* torusMaterial = new Qt3DExtras::QPhongMaterial();
    torusMaterial->setDiffuse(QColor(QRgb(0xbeb32b)));
    //! [2]

    {
        // Torus
        //! [3]
        m_torusEntity = new Qt3DCore::QEntity(m_rootEntity);
        m_torusEntity->addComponent(m_torus);
        m_torusEntity->addComponent(torusMaterial);
        m_torusEntity->addComponent(torusTransform);
        //! [3]
    }
}

Torus::~Torus()
{
}
void Torus::enableTorus(bool enabled) {

}