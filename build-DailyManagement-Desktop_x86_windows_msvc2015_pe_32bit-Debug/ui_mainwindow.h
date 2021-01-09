/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QToolButton *user_off;
    QToolButton *todo_off;
    QToolButton *calendar_off;
    QToolButton *count_down_off;
    QToolButton *dustbin_off;
    QToolButton *search_off;
    QToolButton *log_off;
    QToolButton *setting_off;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1600, 975);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 60, 975));
        user_off = new QToolButton(widget);
        user_off->setObjectName(QStringLiteral("user_off"));
        user_off->setGeometry(QRect(6, 45, 45, 45));
        QFont font;
        font.setPointSize(1);
        user_off->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/user_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        user_off->setIcon(icon);
        user_off->setIconSize(QSize(45, 45));
        user_off->setCheckable(false);
        user_off->setAutoRaise(true);
        todo_off = new QToolButton(widget);
        todo_off->setObjectName(QStringLiteral("todo_off"));
        todo_off->setGeometry(QRect(6, 125, 45, 45));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/todo_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        todo_off->setIcon(icon1);
        todo_off->setIconSize(QSize(45, 45));
        todo_off->setAutoRaise(true);
        calendar_off = new QToolButton(widget);
        calendar_off->setObjectName(QStringLiteral("calendar_off"));
        calendar_off->setGeometry(QRect(6, 205, 45, 45));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/calendar_off .png"), QSize(), QIcon::Normal, QIcon::Off);
        calendar_off->setIcon(icon2);
        calendar_off->setIconSize(QSize(45, 45));
        calendar_off->setAutoRaise(true);
        count_down_off = new QToolButton(widget);
        count_down_off->setObjectName(QStringLiteral("count_down_off"));
        count_down_off->setGeometry(QRect(6, 285, 45, 45));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/count_down_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        count_down_off->setIcon(icon3);
        count_down_off->setIconSize(QSize(45, 45));
        count_down_off->setAutoRaise(true);
        dustbin_off = new QToolButton(widget);
        dustbin_off->setObjectName(QStringLiteral("dustbin_off"));
        dustbin_off->setGeometry(QRect(6, 365, 45, 45));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/dustbin_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        dustbin_off->setIcon(icon4);
        dustbin_off->setIconSize(QSize(45, 45));
        dustbin_off->setAutoRaise(true);
        search_off = new QToolButton(widget);
        search_off->setObjectName(QStringLiteral("search_off"));
        search_off->setGeometry(QRect(6, 442, 45, 45));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/search_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        search_off->setIcon(icon5);
        search_off->setIconSize(QSize(45, 45));
        search_off->setAutoRaise(true);
        log_off = new QToolButton(widget);
        log_off->setObjectName(QStringLiteral("log_off"));
        log_off->setGeometry(QRect(6, 522, 45, 45));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/log_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        log_off->setIcon(icon6);
        log_off->setIconSize(QSize(45, 45));
        log_off->setAutoRaise(true);
        setting_off = new QToolButton(widget);
        setting_off->setObjectName(QStringLiteral("setting_off"));
        setting_off->setGeometry(QRect(6, 602, 45, 45));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icon/setting_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        setting_off->setIcon(icon7);
        setting_off->setIconSize(QSize(45, 45));
        setting_off->setAutoRaise(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        user_off->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        todo_off->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        calendar_off->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        count_down_off->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        dustbin_off->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        search_off->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        log_off->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        setting_off->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
