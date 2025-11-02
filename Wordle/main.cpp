#include "Application.h"
#include "MainWindow.h"
#include "Settings.h"

int main(int argc, char *argv[])
{
    Application app(argc, argv);
    Settings settings;
    MainWindow window;
    window.show();
    return app.exec();
}
