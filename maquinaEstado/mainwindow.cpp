#include "mainwindow.h"
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QLabel"
#include "QPushButton"
#include "QTimer"
#include "QSpacerItem"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500, 300);
    setMaximumWidth(800);
    setMaximumHeight(600);
    setWindowTitle("Máquina de Estado");
    QWidget *widget = new QWidget();
    setCentralWidget(widget);

    QVBoxLayout *vLayout = new QVBoxLayout(widget);
    QHBoxLayout *hLayout = new QHBoxLayout();
    QSpacerItem *spacer = new QSpacerItem(100, 100);
    QLabel *contador = new QLabel("Parado"); //Quero que inicie com algo; talvez fazer uma memória pra praticar
    QFont f("Arial", 30, QFont::Bold);
    contador->setFont(f);
    contador->setStyleSheet("color: red;");
    QPushButton *cresc = new QPushButton("Crescente");
    QPushButton *decr = new QPushButton("Decrescente");
    QPushButton *start = new QPushButton("Iniciar");
    QPushButton *stop = new QPushButton("Parar");

    cresc->setToolTip("Sentido crescente para a máquina de estado.");
    decr->setToolTip("Sentido decrescente para a máquina de estado.");
    start->setToolTip("Inicia a máquina de estado.");
    stop->setToolTip("Para a máquina de estado.");


    vLayout->addWidget(contador, 0, Qt::AlignCenter);
    vLayout->addLayout(hLayout);
    vLayout->addSpacerItem(spacer);
    hLayout->addWidget(cresc);
    hLayout->addWidget(start);
    hLayout->addWidget(stop);
    hLayout->addWidget(decr);

    QTimer *timer = new QTimer(widget);
    timer->setInterval(1000);

    cresc->setEnabled(false);
    stop->setEnabled(false);
    connect(start, &QPushButton::clicked, [this, contador, timer, start, stop]() {
        contador->setText(QString::number(estado));
        if(!timer->isActive()) {
            timer->start();
        }
        contador->setStyleSheet("color: blue");
        start->setEnabled(false);
        stop->setEnabled(true);
        stopped = false;
    });

    connect(stop, &QPushButton::clicked, [this, timer, contador, start, stop]() {
        if(timer->isActive()) timer->stop();
        contador->setStyleSheet("color: red;");
        start->setEnabled(true);
        stop->setEnabled(false);
        stopped = true;
    });

    connect(timer, &QTimer::timeout, [this, contador]() {
        if(dir == 0)
            mudaEstadoCrescente();
        else if(dir == 1)
            this->mudaEstadoDecrescente();
        contador->setText(QString::number(estado));
    });

    connect(cresc, &QPushButton::clicked, [this, cresc, decr]() {
        dir = 0;
        cresc->setEnabled(false);
        decr->setEnabled(true);
    });
    connect(decr, &QPushButton::clicked, [this, cresc, decr]() {
        dir = 1;
        cresc->setEnabled(true);
        decr->setEnabled(false);
    });


    QTimer *timerPisca = new QTimer(widget);
    timerPisca->setInterval(500);
    timerPisca->start();
    auxPisca = false;
    connect(timerPisca, &QTimer::timeout, [this, contador]() {
        if(stopped) {
            if(auxPisca) {
                contador->setStyleSheet("color: rgba(255, 0, 0, 0.4);");
                auxPisca = false;
            } else {
                contador->setStyleSheet("color: rgba(255, 0, 0, 1.0);");
                auxPisca = true;
            }
        }
    });

}

MainWindow::~MainWindow()
{
}

void MainWindow::mudaEstadoCrescente() {
    switch (estado) {
        case 0: estado = 1; break;
        case 1: estado = 2; break;
        case 2: estado = 3; break;
        case 3: estado = 4; break;
        case 4: estado = 5; break;
        case 5: estado = 6; break;
        case 6: estado = 7; break;
        case 7: estado = 8; break;
        case 8: estado = 9; break;
        case 9: estado = 10; break;
        case 10: estado = 11; break;
        case 11: estado = 12; break;
        case 12: estado = 13; break;
        case 13: estado = 14; break;
        case 14: estado = 15; break;
        case 15: estado = 0; break;
        default: estado = 0; break;
    }
}

void MainWindow::mudaEstadoDecrescente() {
    switch (estado) {
        case 0: estado = 15; break;
        case 1: estado = 0; break;
        case 2: estado = 1; break;
        case 3: estado = 2; break;
        case 4: estado = 3; break;
        case 5: estado = 4; break;
        case 6: estado = 5; break;
        case 7: estado = 6; break;
        case 8: estado = 7; break;
        case 9: estado = 8; break;
        case 10: estado = 9; break;
        case 11: estado = 10; break;
        case 12: estado = 11; break;
        case 13: estado = 12; break;
        case 14: estado = 13; break;
        case 15: estado = 14; break;
        default: estado = 0; break;
    }
}
