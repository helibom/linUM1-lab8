#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    // setup connections
    // exit button
    connect(ui->pushButtonExit, SIGNAL (clicked(bool)), QApplication::instance(), SLOT (quit()) );
    // increase & decrease button step increment
    connect(ui->spinBoxStep, SIGNAL (valueChanged(int)), this, SLOT (onStepChange(int)) );
    //
    connect(this, SIGNAL (sliderNewValue(int)), this, SLOT (onNewSliderValue(int)) );
    connect(ui->pushButtonIncrease, SIGNAL (clicked(bool)), this, SLOT (onButtonSliderIncrease(bool)) );
    connect(ui->pushButtonDecrease, SIGNAL (clicked(bool)), this, SLOT (onButtonSliderDecrease(bool)) );

    // setup max threshold dialog notice
    this->dialog = new Dialog(this);
    this->dialog->setWindowTitle("ATTENTION");
    connect(this, SIGNAL (sliderReachedMax()), this, SLOT (onSliderReachedMax()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStepChange(int step) {
    this->step = step;
    std::cout << "Step: " << this->step << std::endl;
}

void MainWindow::onButtonSliderIncrease(bool clicked) {
    // get current
    int red = this->ui->verticalSliderRed->value();
    int green = this->ui->verticalSliderGreen->value();
    int blue = this->ui->verticalSliderBlue->value();
    // update
    this->ui->verticalSliderRed->setValue(red + this->step);
    this->ui->verticalSliderGreen->setValue(green + this->step);
    this->ui->verticalSliderBlue->setValue(blue + this->step);
    // notify ui
    emit sliderNewValue(this->ui->verticalSliderRed->value());
    emit sliderNewValue(this->ui->verticalSliderGreen->value());
    emit sliderNewValue(this->ui->verticalSliderBlue->value());
}

void MainWindow::onButtonSliderDecrease(bool clicked) {
    // get current
    int red = this->ui->verticalSliderRed->value();
    int green = this->ui->verticalSliderGreen->value();
    int blue = this->ui->verticalSliderBlue->value();
    // update
    this->ui->verticalSliderRed->setValue(red - this->step);
    this->ui->verticalSliderGreen->setValue(green - this->step);
    this->ui->verticalSliderBlue->setValue(blue - this->step);
    // notify ui
    emit sliderNewValue(this->ui->verticalSliderRed->value());
    emit sliderNewValue(this->ui->verticalSliderGreen->value());
    emit sliderNewValue(this->ui->verticalSliderBlue->value());
}

void MainWindow::onSliderReachedMax() {
    this->dialog->setVisible(true);
}

void MainWindow::onNewSliderValue(int val) {
    if (val >= 99 || val <= 0) {
        this->dialog->setVisible(true);
    };
}
