#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "QVBoxLayout"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QVBoxLayout *vlayout = new QVBoxLayout(ui->centralWidget);
    QPushButton *btn = new QPushButton("Fechar!", ui->centralWidget);

    //vlayout->insertWidget(0, btn);

    connect(btn, &QPushButton::clicked, [this](bool) {
        this->close();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
