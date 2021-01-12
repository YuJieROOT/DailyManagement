#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QMainWindow>

#include "calendarPage.h"
#include "countdownPage.h"
#include "dustbinPage.h"
#include "logPage.h"
#include "settingPage.h"
#include "todoPage.h"
#include "userPage.h"

namespace Ui {
class searchPage;
}

class searchPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit searchPage(QWidget *parent = nullptr);
    ~searchPage();

private slots:
    void on_user_button_clicked();

    void on_todo_button_clicked();

    void on_calendar_button_clicked();

    void on_count_down_button_clicked();

    void on_dustbin_button_clicked();

    void on_log_button_clicked();

    void on_setting_button_clicked();

private:
    Ui::searchPage *ui;
};

#endif // SEARCHPAGE_H
