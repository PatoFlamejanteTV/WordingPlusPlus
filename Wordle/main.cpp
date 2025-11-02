#include "Application.h"
#include "MainWindow.h"
#include "Settings.h"

Settings *settings;

int main(int argc, char *argv[])
{
    Application app(argc, argv);
    settings = new Settings(&app);
    MainWindow window;
    window.show();
    return app.exec();
}
