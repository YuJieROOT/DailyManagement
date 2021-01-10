#include "settingPage.h"
#include "ui_settingPage.h"

settingPage::settingPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::settingPage)
{
    ui->setupUi(this);
}

settingPage::~settingPage()
{
    delete ui;
}
