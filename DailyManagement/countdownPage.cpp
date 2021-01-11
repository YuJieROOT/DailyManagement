#include "countdownPage.h"
#include "ui_countdownPage.h"

countDownPage::countDownPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::countDownPage)
{
    ui->setupUi(this);
}

countDownPage::~countDownPage()
{
    delete ui;
}
