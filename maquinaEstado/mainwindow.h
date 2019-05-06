#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    int estado = 0;
    void mudaEstadoCrescente();
    void mudaEstadoDecrescente();
    int dir = 0;
    bool stopped = false;
    bool auxPisca;
};

#endif // MAINWINDOW_H
