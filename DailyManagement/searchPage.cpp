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

void searchPage::on_user_button_clicked()
{
    userPage *w = new userPage;
    w->show();
    this->close();
    delete this;
}

void searchPage::on_todo_button_clicked()
{
    todoPage *w = new todoPage;
    w->show();
    this->close();
    delete this;
}

void searchPage::on_calendar_button_clicked()
{
    calendarPage *w = new calendarPage;
    w->show();
    this->close();
    delete this;
}

void searchPage::on_count_down_button_clicked()
{
    countDownPage *w = new countDownPage;
    w->show();
    this->close();
    delete this;
}

void searchPage::on_dustbin_button_clicked()
{
    dustbinPage *w = new dustbinPage;
    w->show();
    this->close();
    delete this;
}

void searchPage::on_log_button_clicked()
{
    logPage *w = new logPage;
    w->show();
    this->close();
    delete this;
}

void searchPage::on_setting_button_clicked()
{
    settingPage *w = new settingPage;
    w->show();
    this->close();
    delete this;
}
