#include "window.h"

#include <QApplication>
#include <QPushButton>

Window::Window(QWidget *parent) :
 QWidget(parent)
 {
    // Set size of the window
    // setFixedSize(100, 50);

    // Create and position the button
    m_button = new QPushButton("Exit", this);
    m_button->setGeometry(200, 5, 80, 30);

    connect(m_button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
}
