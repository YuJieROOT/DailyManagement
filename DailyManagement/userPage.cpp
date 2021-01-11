#include "userPage.h"
#include "ui_userPage.h"

userPage::userPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userPage)
{
    ui->setupUi(this);
}

userPage::~userPage()
{
    delete ui;
}

void userPage::on_todo_button_clicked()
{
    todoPage *w = new todoPage;
    w->show();
    this->close();
    delete this;
}

void userPage::on_calendar_button_clicked()
{
    calendarPage *w = new calendarPage;
    w->show();
    this->close();
    delete this;
}
