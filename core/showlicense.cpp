#include "showlicense.h"
#include "licensedialog.h"
#include <QApplication>
#include <QThread>
#include <QFile>
#include <QDebug>
LicenseDialog* LICENSEDIALOG = NULL;
QApplication* APPLICATION = NULL;
bool licenseAccepted = false;



void populateDialog(std::vector<std::string> libraries) {
    for(int i=0;i<libraries.size();i++) {
        QString libText =  QString::fromStdString(libraries[i]);
        QStringList list = libText.split("#");
        if(list.size() < 2)
            continue;
        QString licenseText = "";
        if(list.size() >= 3) {
            QFile licenseTextFile(":/" + list.at(2) + ".txt");
            if(licenseTextFile.exists()) {
               licenseTextFile.open(QIODevice::ReadOnly);
               licenseText = QString::fromStdString(licenseTextFile.readAll().toStdString());
               licenseTextFile.close();
            }
        }
        LICENSEDIALOG->addTab(list.at(0), list.at(1), licenseText);
    }
}
void showLicenseDialog(std::vector<std::string> libraries) {
    if(LICENSEDIALOG == NULL) {
        LICENSEDIALOG = (new LicenseDialog());
        populateDialog(libraries);
    }
    LICENSEDIALOG->show();
}

void showLicenseDialog() {
    if(LICENSEDIALOG != NULL)
        LICENSEDIALOG->show();
}

bool waitLicenseDialogAccepted() {
    while(LICENSEDIALOG->isVisible())
        refreshLicenseDialog();
    return LICENSEDIALOG->isAccepted();
}

void refreshLicenseDialog() {
    QApplication::processEvents();
    QThread::msleep(10);
}


void initializeLicenseDialog() {
    int a = 0;
    char* b[1];
    APPLICATION = new QApplication(a, b);
}

bool hasLicenseAccepted() {
    return licenseAccepted;
}
