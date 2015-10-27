#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{


    centralWidget = new QGroupBox();
    codeEditorsBox = new QGroupBox(centralWidget);
    vsStatusBox = new QGroupBox(codeEditorsBox);
    fsStatusBox = new QGroupBox(codeEditorsBox);

    hlayout = new QHBoxLayout(centralWidget);
    vlayout = new QVBoxLayout(codeEditorsBox);

    vsStatusLayout = new QHBoxLayout(vsStatusBox);
    fsStatusLayout = new QHBoxLayout(fsStatusBox);

    glwidget = new MyGLWidget(centralWidget);
    fstextbox = new QPlainTextEdit(codeEditorsBox);
    vstextbox = new QPlainTextEdit(codeEditorsBox);

    //status stuff:
    vsAcceptButton = new QPushButton(vsStatusBox);
    fsAcceptButton = new QPushButton(fsStatusBox);

    vsStatusLabel = new QLabel(vsStatusBox);
    fsStatusLabel = new QLabel(fsStatusBox);

    setCentralWidget(centralWidget);
    centralWidget->setLayout(hlayout);
    codeEditorsBox->setLayout(vlayout);
    vsStatusBox->setLayout(vsStatusLayout);
    fsStatusBox->setLayout(fsStatusLayout);

    hlayout->addWidget(glwidget,1);

    hlayout->addWidget(codeEditorsBox,1);

    vlayout->addWidget(vstextbox,1);
    vlayout->addWidget(vsStatusBox);

    vlayout->addWidget(fstextbox,1);
    vlayout->addWidget(fsStatusBox);

    vsStatusLayout->addWidget(vsAcceptButton);
    vsStatusLayout->addWidget(vsStatusLabel);

    fsStatusLayout->addWidget(fsAcceptButton);
    fsStatusLayout->addWidget(fsStatusLabel);

    //set Labels etc:
    vsAcceptButton->setText("update vertex shader");
    fsAcceptButton->setText("update fragment shader");

    vsStatusLabel->setText("vs status:");
    fsStatusLabel->setText("fs status:");



}

//=============================================================================

MainWindow::~MainWindow()
{

    delete centralWidget;
    //delete hlayout;
    //delete glwidget;
    //delete textbox;
}

