#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{


    centralWidget = new QGroupBox();
    hlayout = new QHBoxLayout(centralWidget);
    glwidget = new MyGLWidget(centralWidget);
    textbox = new QPlainTextEdit(centralWidget);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(hlayout);


    hlayout->addWidget(glwidget,1);
    hlayout->addWidget(textbox,1);

}

//=============================================================================

MainWindow::~MainWindow()
{

    //delete centralWidget;
    //delete hlayout;
    //delete glwidget;
    //delete textbox;
}

