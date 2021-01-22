#include "todoPage.h"
#include "ui_todoPage.h"
#include <QTime>
#include <QScrollArea>
#include <QScrollBar>

todoPage::todoPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::todoPage)
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

todoPage::~todoPage()
{
    delete ui;
}


void todoPage::on_user_button_clicked()
{
    userPage *w = new userPage;
    w->show();
    QTime dieTime = QTime::currentTime().addMSecs(300);//延时300毫秒
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    this->close();
    delete this;
}

void todoPage::on_calendar_button_clicked()
{
    calendarPage *w = new calendarPage;
    w->show();
    this->close();
    delete this;
}

void todoPage::on_count_down_button_clicked()
{
    countDownPage *w = new countDownPage;
    w->show();
    this->close();
    delete this;
}

void todoPage::on_dustbin_button_clicked()
{
    dustbinPage *w = new dustbinPage;
    w->show();
    this->close();
    delete this;
}


void todoPage::on_search_button_clicked()
{
    searchPage *w = new searchPage;
    w->show();
    this->close();
    delete this;
}

void todoPage::on_log_button_clicked()
{
    logPage *w = new logPage;
    w->show();
    this->close();
    delete this;
}

void todoPage::on_setting_button_clicked()
{
    settingPage *w = new settingPage;
    w->show();
    this->close();
    delete this;
}
