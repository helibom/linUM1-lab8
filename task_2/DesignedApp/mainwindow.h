#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    Dialog *dialog;
    int step;

signals:
    void sliderReachedMax();
    void sliderNewValue(int);

private slots:
    void onStepChange(int step);
    void onButtonSliderIncrease(bool clicked);
    void onButtonSliderDecrease(bool clicked);
    void onNewSliderValue(int newValue);
    void onSliderReachedMax();

};
#endif // MAINWINDOW_H
