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

private:
    Ui::searchPage *ui;
};

#endif // SEARCHPAGE_H
