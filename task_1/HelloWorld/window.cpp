#include "window.h"

#include <QApplication>
#include <QPushButton>
#include <iostream>

Window::Window(QWidget *parent) : QWidget(parent)
{
   // Set size of the window
//   setFixedSize(100, 50);

   // Create and position the button
   m_button = new QPushButton("Hello Unchecked Button", this);
   m_button->setGeometry(350, 200, 150, 100);
   m_button->setCheckable(true);

   m_counter = 0;

   connect(m_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
   connect(this, SIGNAL (counterReachedTen()), QApplication::instance(), SLOT (quit()));
}

void Window::slotButtonClicked(bool checked)
{
   if (checked)
   {
      m_button->setText("Checked");
   }
   else
   {
      m_button->setText("Hello Unchecked Button");
   }

   m_counter++;
   std::cout << "Counter: " << m_counter << std::endl;

   if (m_counter == 10) {
       emit counterReachedTen();
   }
}
