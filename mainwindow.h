#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>

#include "myglwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    QGroupBox *centralWidget;
    QGroupBox *codeEditorsBox;
    QGroupBox *vsStatusBox;
    QGroupBox *fsStatusBox;

    QPlainTextEdit *fstextbox;
    QPlainTextEdit *vstextbox;
    QHBoxLayout *hlayout;
    QVBoxLayout *vlayout;

    MyGLWidget *glwidget;

    QHBoxLayout *vsStatusLayout;
    QHBoxLayout *fsStatusLayout;

    QLabel *vsStatusLabel;
    QLabel *fsStatusLabel;

    QPushButton *vsAcceptButton;
    QPushButton *fsAcceptButton;



};

#endif // MAINWINDOW_H
