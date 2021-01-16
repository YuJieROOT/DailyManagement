#include "userPage.h"
#include "ui_userPage.h"

userPage::userPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userPage)
{
    ui->setupUi(this);
    this->setStyleSheet(
                "QScrollArea{"
                    "border: 0px solid;"
                    "border-right-width: 1px;"
                    "border-right-color: #dcdbdc;"
                    "background-color: #f5f5f7;"
                "}"

                "QScrollBar:vertical {"
                    "border: none;"
                    "background: #f5f5f7;"
                    "width: 10px;"
                    "margin: 0px 0 0px 0;"
                "}"

                "QScrollBar::handle:vertical {"
                    "background: Gainsboro;"
                    "min-height: 20px;"
                    "border-radius: 5px;"
                    "border: none;"
                "}"

                "QScrollBar::add-line:vertical {"
                    "border: 0px solid grey;"
                    "background: #32CC99;"
                    "height: 0px;"
                    "subcontrol-position: bottom;"
                    "subcontrol-origin: margin;"
                "}"

                "QScrollBar::sub-line:vertical {"
                    "border: 0px solid grey;"
                    "background: #32CC99;"
                    "height: 0px;"
                    "subcontrol-position: top;"
                    "subcontrol-origin: margin;"
                "}"

                "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
                    "background: none;"
                    "width: 0px;"
                    "height: 0px;"
                "}"

                );
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
