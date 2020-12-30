#include "showlicense.h"
#include "licensedialog.h"
#include <QApplication>

LicenseDialog* LICENSEDIALOG = NULL;
QApplication* APPLICATION = NULL;

void showLicenseDialog(std::vector<std::string> libraries) {
    Q_UNUSED(libraries); //TODO
    if(LICENSEDIALOG == NULL) {
        LICENSEDIALOG = (new LicenseDialog());
    }
    LICENSEDIALOG->show();
}

void refreshLicenseDialog() {
    QApplication::processEvents();
}


void initializeLicenseDialog() {
    int a = 0;
    char* b = new char[0];
    APPLICATION = new QApplication(a, &b);
}
