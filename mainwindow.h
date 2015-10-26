#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QWidget>
#include <QGroupBox>

#include "myglwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    QGroupBox *centralWidget;
    QPlainTextEdit *textbox;
    QHBoxLayout *hlayout;
    MyGLWidget *glwidget;

};

#endif // MAINWINDOW_H
