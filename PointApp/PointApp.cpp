#include "PointApp.h"
#include "ToolBox.h"
#include "Canvas.h"
#include "ColorBar.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>

#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include <QApplication>
#include<PropertyPanel.h>

PointApp::PointApp(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("DPoint");
    resize(900, 600);

    createMenu();
    createLayout();
}

PointApp::~PointApp()
{}


// for file i use this :https://zetcode.com/gui/qt5/files/
void PointApp::newFile()
{
    QMessageBox::StandardButtons reply;
    //if (!currentFile.isEmpty()) {
    //    canvas->clear();
    //}
    //else {
    //    reply = QMessageBox::question(
    //        this,
    //        "New file",
    //        "Save before closing?",
    //        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
    //    );
    //    if (reply == QMessageBox::Yes) {
    //        saveFile();
    //        canvas->clear();
    //    }
    //    else if (reply == QMessageBox::No) {
    //        canvas->clear();
    //    }
    //}

    reply = QMessageBox::question(
        this,
        "New file",
        "Save before closing?",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel
    );
    if (reply == QMessageBox::Yes) {
        saveSTL();
    }
    else if (reply == QMessageBox::No) {
    }
    
}

void PointApp::openFile()
{
    QString filename = QFileDialog::getOpenFileName(
        this,
        "open file",
        "",
        "Text Files (*.txt)"
    );
    if (filename.isEmpty()) {
        return;
    }
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly| QIODevice::Text)) {
        QTextStream in(&file);
        file.close();

        currentFile = filename;
    }
}

void PointApp::saveSTL()
{
    QString filename;
    if (currentFile.isEmpty()) {
        filename = QFileDialog::getSaveFileName(
            this,
            "Save file",
            "",
            "Text Files(*.txt)"
        );
    }
    else {
        filename = currentFile;
    }
    if (filename.isEmpty()) {
        return;
    }
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        file.close();

        currentFile = filename;
    }

}

void PointApp::exitApp()
{
    QApplication::quit();

}

void PointApp::createMenu()
{
    //resource i use:https://doc.qt.io/qt-6/qtwidgets-mainwindows-menus-example.html
    //https://zetcode.com/gui/qt5/menusandtoolbars/

    QMenu* file = menuBar()->addMenu("File");

    QAction* newAct = file->addAction("New");
    QAction* openAct = file->addAction("Open");
    QAction* saveAct = file->addAction("Save");
    file->addAction("Print");
    QAction* exitAct = file->addAction("Exit");
        
    connect(newAct, &QAction::triggered, this, &PointApp::newFile);
    connect(openAct, &QAction::triggered, this, &PointApp::openFile);
    connect(saveAct, &QAction::triggered, this, &PointApp::saveSTL);
    connect(exitAct, &QAction::triggered, this, &PointApp::exitApp);

    QMenu* edit = menuBar()->addMenu("Edit");
    edit->addAction("Undo");
    edit->addAction("Redo");
    edit->addAction("Cut");
    edit->addAction("Copy");
    edit->addAction("Paste");

    QMenu* view = menuBar()->addMenu("View");
    view->addAction("Zoom In");
    view->addAction("Zoom Out");

    QMenu* modify = menuBar()->addMenu("Modify");
    modify->addAction("Move");
    modify->addAction("Rotate");

    QMenu* help = menuBar()->addMenu("Help");
    help->addAction("Documentation");
    help->addAction("Tutorials");
    help->addAction("About");
 

}

void PointApp::createLayout()
{

    QWidget* central = new QWidget;
    setCentralWidget(central);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *workspaceLayout = new QHBoxLayout();
    

    toolBox = new ToolBox;
    canvas = new Canvas;
    propertyPanel = new PropertyPanel;

    workspaceLayout->addWidget(toolBox);
    workspaceLayout->addWidget(canvas);
    workspaceLayout->addWidget(propertyPanel);
    colorBar = new ColorBar;

    mainLayout->addLayout(workspaceLayout);
    //mainLayout->addWidget(colorBar);

    central->setLayout(mainLayout);

    //connect(colorBar, &ColorBar::colorSelected, canvas, &Canvas::setColor);
    connect(toolBox, &ToolBox::toolSelected,canvas, &Canvas::showTool);
    connect(toolBox, &ToolBox::toolSelected, propertyPanel, &PropertyPanel::updateName);

    statusBar()->showMessage("Lower Bar");

}




