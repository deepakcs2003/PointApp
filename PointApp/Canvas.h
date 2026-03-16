#pragma once
#include <QWidget>

#include <Qt3DExtras/qt3dwindow.h>
#include <BaseShape.h>

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget* parent = nullptr);
    ~Canvas();

public slots:
    void onToolSelected( QString toolName);

signals:
    void shapeAdded(BaseShape* shape);

private:

    Qt3DExtras::Qt3DWindow* view;
    QWidget* container;

    Qt3DCore::QEntity* rootEntity;

    QMap<QString, BaseShape*>shapes;
};

