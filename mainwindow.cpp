#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{


    centralWidget = new QGroupBox();
    hlayout = new QHBoxLayout(centralWidget);
    glwidget = new MyGLWidget(centralWidget);
    textbox = new QPlainTextEdit(centralWidget);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(hlayout);
    hlayout->addWidget(glwidget);
    hlayout->addWidget(textbox);

    hlayout->addStretch();



}

//=============================================================================

MainWindow::~MainWindow()
{

    //delete centralWidget;
    //delete hlayout;
    //delete glwidget;
    //delete textbox;
}

