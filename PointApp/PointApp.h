#pragma once

#include <QtWidgets/QMainWindow>
#include "ToolBox.h"
#include "ColorBar.h"
#include "Canvas.h"
#include<PropertyPanel.h>
#include <BaseShape.h>

class PointApp : public QMainWindow
{
    Q_OBJECT

public:
    PointApp(QWidget *parent = nullptr);
    ~PointApp();

private slots:
    void onShapeAdded(BaseShape* shape);

    void newFile();
    void openFile();
    void saveSTL();
    void exitApp();

private:
    void createMenu();
    void createLayout();
    ToolBox *toolBox;
    Canvas *canvas;
    PropertyPanel* propertyPanel;

    QString currentFile;

};

