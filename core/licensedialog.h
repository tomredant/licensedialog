#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H
#include <QWidget>
#include <QDialog>

namespace Ui {
class AboutWindow;
}

class LicenseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LicenseDialog(QWidget *parent = nullptr);
    ~LicenseDialog();
    void addTab(QString name, QString header, QString licenseText = "", int tabNum = 0);
    bool isAccepted();
public slots:
    void acceptAndClose();
    void rejectAndClose();

private:
    Ui::AboutWindow *m_ui;
    bool m_accepted;
};

#endif // ABOUTWINDOW_H
