#include <QApplication>
#include <QProgressBar>
#include <QSlider>

#include "window.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    Window window;
    window.setFixedSize(700, 400);

    window.show();

    // Connection
    // This connection set the value of the progress bar
    // while the slider's value changes
//    QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));

    return app.exec();
}
