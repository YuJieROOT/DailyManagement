#ifndef DUSTBINPAGE_H
#define DUSTBINPAGE_H

#include <QMainWindow>

#include "calendarPage.h"
#include "countdownPage.h"
#include "logPage.h"
#include "searchPage.h"
#include "settingPage.h"
#include "todoPage.h"
#include "userPage.h"

namespace Ui {
class dustbinPage;
}

class dustbinPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit dustbinPage(QWidget *parent = nullptr);
    ~dustbinPage();

private slots:
    void on_user_button_clicked();

    void on_todo_button_clicked();

    void on_calendar_button_clicked();

    void on_count_down_button_clicked();

    void on_search_button_clicked();

    void on_log_button_clicked();

    void on_setting_button_clicked();

private:
    Ui::dustbinPage *ui;
};

#endif // DUSTBINPAGE_H
