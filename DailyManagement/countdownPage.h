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

private:
    Ui::countDownPage *ui;
};

#endif // COUNTDOWNPAGE_H
