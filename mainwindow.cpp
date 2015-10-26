#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{


    centralWidget = new QGroupBox();
    codeEditors = new QGroupBox(centralWidget);

    hlayout = new QHBoxLayout(centralWidget);
    vlayout = new QVBoxLayout(codeEditors);

    glwidget = new MyGLWidget(centralWidget);
    fstextbox = new QPlainTextEdit(codeEditors);
    vstextbox = new QPlainTextEdit(codeEditors);

    setCentralWidget(centralWidget);
    centralWidget->setLayout(hlayout);


    hlayout->addWidget(glwidget,1);
    codeEditors->setLayout(vlayout);
    hlayout->addWidget(codeEditors,1);

    vlayout->addWidget(vstextbox,1);
    vlayout->addWidget(fstextbox,1);



}

//=============================================================================

MainWindow::~MainWindow()
{

    delete centralWidget;
    //delete hlayout;
    //delete glwidget;
    //delete textbox;
}

