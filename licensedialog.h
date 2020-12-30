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

private:
    Ui::AboutWindow *m_ui;
};

#endif // ABOUTWINDOW_H
