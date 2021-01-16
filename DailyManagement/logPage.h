#ifndef LOGPAGE_H
#define LOGPAGE_H

#include <QMainWindow>

#include "calendarPage.h"
#include "countdownPage.h"
#include "dustbinPage.h"
#include "searchPage.h"
#include "settingPage.h"
#include "todoPage.h"
#include "userPage.h"

namespace Ui {
class logPage;
}

class logPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit logPage(QWidget *parent = nullptr);
    ~logPage();

private slots:
    void on_user_button_clicked();

    void on_todo_button_clicked();

    void on_calendar_button_clicked();

    void on_count_down_button_clicked();

    void on_dustbin_button_clicked();

    void on_search_button_clicked();

    void on_setting_button_clicked();

private:
    Ui::logPage *ui;
};

#endif // LOGPAGE_H
