#ifndef COUNTDOWNPAGE_H
#define COUNTDOWNPAGE_H

#include <QMainWindow>

#include "calendarPage.h"
#include "dustbinPage.h"
#include "logPage.h"
#include "searchPage.h"
#include "settingPage.h"
#include "todoPage.h"
#include "userPage.h"

namespace Ui {
class countDownPage;
}

class countDownPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit countDownPage(QWidget *parent = nullptr);
    ~countDownPage();


private slots:
    void on_user_button_clicked();

    void on_todo_button_clicked();

    void on_calendar_button_clicked();

    void on_dustbin_button_clicked();

    void on_search_button_clicked();

    void on_log_button_clicked();

    void on_setting_button_clicked();

private:
    Ui::countDownPage *ui;
};

#endif // COUNTDOWNPAGE_H
