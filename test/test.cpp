
#include "showlicense.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::vector<std::string> libsToShow;
    libsToShow.push_back("Qt5.15.3#custom text#lgpl-3.0");
    showLicenseDialog(libsToShow);
    return a.exec();
}
