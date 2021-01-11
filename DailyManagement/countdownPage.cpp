#include "countdownPage.h"
#include "ui_countdownPage.h"
#include <QTime>

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

void countDownPage::on_user_button_clicked()
{
    userPage *w = new userPage;
    w->show();
    this->close();
    delete this;
}


void countDownPage::on_todo_button_clicked()
{
    todoPage *w = new todoPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::on_calendar_button_clicked()
{
    calendarPage *w = new calendarPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::on_dustbin_button_clicked()
{
    dustbinPage *w = new dustbinPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::on_search_button_clicked()
{
    searchPage *w = new searchPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::on_log_button_clicked()
{
    logPage *w = new logPage;
    w->show();
    this->close();
    delete this;
}

void countDownPage::on_setting_button_clicked()
{
    settingPage *w = new settingPage;
    w->show();
    this->close();
    delete this;
}
