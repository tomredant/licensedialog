#include "licensedialog.h"
#include "ui_licensedialog.h"
#include <QPlainTextEdit>
LicenseDialog::LicenseDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::AboutWindow)
{
    Q_INIT_RESOURCE(core);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    m_accepted = false;
    m_ui->setupUi(this);
    while(m_ui->tabWidget->count() > 0)
        m_ui->tabWidget->removeTab(0);
    m_ui->message->setWordWrap(true);
    connect(m_ui->pushButtonAccept,SIGNAL(clicked(bool)),this,SLOT(acceptAndClose()));
    connect(m_ui->pushButtonReject,SIGNAL(clicked(bool)),this,SLOT(rejectAndClose()));
    setWindowTitle(("Gebruiksvoorwaarden"));
}

void LicenseDialog::acceptAndClose() {
    m_accepted = true;
    hide();
}

void LicenseDialog::rejectAndClose() {
    m_accepted = false;
    hide();
    exit(0);
}

void LicenseDialog::addTab(QString name, QString header, QString licenseText, int tabNum) {
    QPlainTextEdit* edit = new QPlainTextEdit();
    if(header.compare("") != 0)
        header += "\n\n";
    if(tabNum==0)
        edit->setPlainText("This software, " + name + ", comes with the following license. " + header + "\n\n" + licenseText);
    else
        edit->setPlainText("This software is based on/built upon " + name + ". The relevant copyright notices and according license text linked to " + name + " are as follows." + header + "\n\n" + licenseText);
    edit->setReadOnly(true);
    m_ui->tabWidget->addTab(edit, QIcon(), name);
}

LicenseDialog::~LicenseDialog()
{
    delete m_ui;
}

bool LicenseDialog::isAccepted() {
    return m_accepted;
}
