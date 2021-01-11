#include "dustbinPage.h"
#include "ui_dustbinPage.h"

dustbinPage::dustbinPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dustbinPage)
{
    ui->setupUi(this);
}

dustbinPage::~dustbinPage()
{
    delete ui;
}
