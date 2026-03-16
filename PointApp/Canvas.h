#pragma once
#include <QWidget>

#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <BaseShape.h>

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget* parent = nullptr);
    ~Canvas();

public slots:
    void onToolSelected(QString toolName);

signals:
    void shapeAdded(BaseShape* shape);

protected:
    bool eventFilter(QObject* obj, QEvent* ev) override;

private:
    QString m_activeTool;
    BaseShape* m_activeShape = nullptr;
    QPoint m_lastMousePos;
    Qt3DExtras::QFirstPersonCameraController* m_camController = nullptr;


    Qt3DExtras::Qt3DWindow* view;
    QWidget* container;

    Qt3DCore::QEntity* rootEntity;

    QMap<QString, BaseShape*>shapes;
};

