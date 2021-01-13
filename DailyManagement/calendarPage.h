#ifndef CALENDARPAGE_H
#define CALENDARPAGE_H

#include <QMainWindow>

#include "countdownPage.h"
#include "dustbinPage.h"
#include "logPage.h"
#include "searchPage.h"
#include "settingPage.h"
#include "todoPage.h"
#include "userPage.h"

namespace Ui {
class calendarPage;
}

class calendarPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit calendarPage(QWidget *parent = nullptr);
    ~calendarPage();

private slots:
    void on_todo_button_clicked();

    void on_user_button_clicked();

    void on_count_down_button_clicked();

    void on_dustbin_button_clicked();

    void on_search_button_clicked();

    void on_log_button_clicked();

    void on_setting_button_clicked();

private:
    Ui::calendarPage *ui;
};

#endif // CALENDARPAGE_H
