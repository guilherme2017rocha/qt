#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "QFrame"
#include "QHBoxLayout"
#include "QLabel"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuBar->close();
    ui->statusBar->close();

    QPushButton *btn = new QPushButton("Clicke me!", ui->centralWidget);
    btn->move(QPoint(ui->centralWidget->width(), ui->centralWidget->height()));

    connect(btn, &QPushButton::clicked, []() {
        QFrame *frame = new QFrame();
        QString str = "Aqui uma janela a vulsa criada pelo btn";
        frame->setWindowTitle(str);
        frame->setFixedWidth(str.size()*10);
        QHBoxLayout *hlayout = new QHBoxLayout(frame);
        hlayout->addWidget(new QLabel("Estre frame foi criado agora!"));
        frame->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
