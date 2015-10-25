#include <iostream>
#include <QApplication>
#include <QPlainTextEdit>

#include "myglwidget.h"

using namespace std;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPlainTextEdit textbox;
    MyGLWidget widget;

    textbox.show();
    widget.show();



    return app.exec();
}

