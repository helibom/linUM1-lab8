#ifndef QPUSHBUTTONSLIDERINCREASER_H
#define QPUSHBUTTONSLIDERINCREASER_H

#include <QAbstractButton>

namespace Ui {
class QPushButtonSliderIncreaser;
}

class QPushButtonSliderIncreaser : public QAbstractButton
{
    Q_OBJECT
public:
    explicit QPushButtonSliderIncreaser(QWidget *parent = nullptr);
    ~QPushButtonSliderIncreaser();
};

#endif // QPUSHBUTTONSLIDERINCREASER_H
