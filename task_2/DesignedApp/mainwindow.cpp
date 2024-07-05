#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // setup
    connect(ui->pushButtonExit, SIGNAL (clicked(bool)), QApplication::instance(), SLOT (quit()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

