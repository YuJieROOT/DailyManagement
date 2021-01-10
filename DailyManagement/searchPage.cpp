#include "searchPage.h"
#include "ui_searchPage.h"

searchPage::searchPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::searchPage)
{
    ui->setupUi(this);
}

searchPage::~searchPage()
{
    delete ui;
}
