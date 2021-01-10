#include "logPage.h"
#include "ui_logPage.h"

logPage::logPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::logPage)
{
    ui->setupUi(this);
}

logPage::~logPage()
{
    delete ui;
}
