#include "calendarPage.h"
#include "ui_calendarPage.h"

#include <QMessageBox>

calendarPage::calendarPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calendarPage)
{
    ui->setupUi(this);
}

calendarPage::~calendarPage()
{
    delete ui;
}

void calendarPage::on_todo_button_clicked()
{
    todoPage *w = new todoPage;
    w->show();
    this->close();
    delete this;
}

void calendarPage::on_user_button_clicked()
{
    userPage *w = new userPage;
    w->show();
    this->close();
    delete this;
}

void calendarPage::on_count_down_button_clicked()
{
    countDownPage *w = new countDownPage;
    w->show();
    this->close();
    delete this;
}

void calendarPage::on_dustbin_button_clicked()
{
    dustbinPage *w = new dustbinPage;
    w->show();
    this->close();
    delete this;
}

void calendarPage::on_search_button_clicked()
{
    searchPage *w = new searchPage;
    w->show();
    this->close();
    delete this;
}

void calendarPage::on_log_button_clicked()
{
    logPage *w = new logPage;
    w->show();
    this->close();
    delete this;
}

void calendarPage::on_setting_button_clicked()
{
    settingPage *w = new settingPage;
    w->show();
    this->close();
    delete this;
}
