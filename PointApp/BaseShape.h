#pragma once
#include <QObject>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QPhongMaterial>
#include <QVector3D>
#include <QColor>
class BaseShape:public QObject
{
	Q_OBJECT
public:
	BaseShape(Qt3DCore::QEntity* rootEntity);
	virtual ~BaseShape();
	virtual QString shapeName() const = 0;

public slots:

    // setter for set the value of value of object dymanically into propertry panel
    void setPositionX(double x);
    void setPositionY(double y);
    void setPositionZ(double z);

    void setScale(double s);

    void setRotationX(double rx);
    void setRotationY(double ry);
    void setRotationZ(double rz);

    void setColor(const QString& colorName);
    void setVisible(bool visible);

public:
     //getter function for get the value of 3d 
     //object and use into propetry pannel to show
     //the property of object when select the particular object;
    QVector3D position() const;
    float scale() const;

    float rotX() const;
    float rotY() const;
    float rotZ() const;

    QColor color() const;
protected:

    Qt3DCore::QEntity* m_rootEntity = nullptr;
    Qt3DCore::QEntity* m_entity = nullptr;
    Qt3DCore::QTransform* m_transform = nullptr;
    Qt3DExtras::QPhongMaterial* m_material = nullptr;
};

