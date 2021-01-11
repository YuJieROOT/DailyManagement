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
