#ifndef SHOWLICENSE_H
#define SHOWLICENSE_H
#include <QVector>
#include <QString>
class LicenseDialog;
extern LicenseDialog* LICENSEDIALOG;
class QApplication;
extern QApplication* APPLICATION;
void initializeLicenseDialog();
void showLicenseDialog(std::vector<std::string> libraries);
void refreshLicenseDialog();

#endif // SHOWLICENSE_H
