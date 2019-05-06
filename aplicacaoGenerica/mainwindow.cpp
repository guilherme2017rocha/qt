#include "mainwindow.h"
#include "QFrame"
#include "QWidget"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QLabel"
#include "QPushButton"
#include "QSettings"
#include "QApplication"
#include "QDebug"
#include "QKeyEvent"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Testando");
    this->resize(600, 400);

    QWidget *widget = new QWidget();
    setCentralWidget(widget);

    QHBoxLayout *hLayout = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout(widget);

    mContador = new QLabel("Oi");
    QPushButton *somar = new QPushButton("Somar");
    QPushButton *subtrair = new QPushButton("Subtrair");
    QPushButton *sair = new QPushButton("Sair");

    vLayout->addLayout(hLayout);
    hLayout->addWidget(somar);
    hLayout->addWidget(mContador, 0, Qt::AlignCenter);
    hLayout->addWidget(subtrair);
    vLayout->addWidget(sair, 0, Qt::AlignHCenter);

    loadSettings();
    connect(somar, &QPushButton::clicked, [this](bool) { i++; mContador->setText(QString::number(i)); });
    connect(subtrair, &QPushButton::clicked, [this](bool) { i--; mContador->setText(QString::number(i)); });
    connect(sair, &QPushButton::clicked, [this]() { this->close(); });

    //keyEnterReceiver* key = new keyEnterReceiver();
    //this->installEventFilter(key);

}

MainWindow::~MainWindow()
{
    QSettings settings(mSettingsFile, QSettings::IniFormat);
    QString valor = (mContador) ? QString::number(i) : "0";
    settings.setValue("contador/valor", valor);
}

void MainWindow::loadSettings() {
    mSettingsFile = QApplication::applicationDirPath() + "/demoSettings2.grt";
    QSettings settings(mSettingsFile, QSettings::IniFormat);
    QString valor = settings.value("contador/valor", "0").toString();
    if(mContador) {
        mContador->setText(valor);
        i = valor.toInt();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if(event->key()==Qt::Key_A) {
        if(!event->isAutoRepeat()) {
            i++;
            mContador->setText(QString::number(i));
        }
    } else if(event->key()==Qt::Key_S) {
        if(!event->isAutoRepeat()) {
            i--;
            mContador->setText(QString::number(i));
        }
    } else if(event->key()==Qt::Key_Escape) {
        this->close();
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {

}
