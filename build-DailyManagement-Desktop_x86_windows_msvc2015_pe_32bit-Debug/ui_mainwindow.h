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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *toolbar;
    QToolButton *user_off;
    QToolButton *todo_off;
    QToolButton *calendar_off;
    QToolButton *count_down_off;
    QToolButton *dustbin_off;
    QToolButton *search_off;
    QToolButton *log_off;
    QToolButton *setting_off;
    QWidget *widget_2;
    QWidget *inbox;
    QWidget *widget_3;
    QToolButton *toolButton;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QWidget *working_place;
    QWidget *widget_6;
    QToolButton *toolButton_2;
    QLabel *label_3;
    QToolButton *toolButton_3;
    QFrame *line_3;
    QWidget *working_place_2;
    QWidget *widget_7;
    QToolButton *toolButton_4;
    QLabel *label_4;
    QToolButton *toolButton_5;
    QFrame *line_4;
    QWidget *new_workplace;
    QToolButton *toolButton_6;
    QLabel *label_5;
    QFrame *line_2;
    QWidget *widget;
    QWidget *widget_4;
    QToolButton *push_button;
    QLabel *label_6;
    QToolButton *toolButton_7;
    QWidget *widget_5;
    QPlainTextEdit *plainTextEdit;
    QFrame *line_5;
    QFrame *line_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget_8;
    QToolButton *toolButton_8;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1600, 975);
        QFont font;
        font.setPointSize(15);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        toolbar = new QWidget(centralwidget);
        toolbar->setObjectName(QStringLiteral("toolbar"));
        toolbar->setGeometry(QRect(0, 0, 60, 975));
        toolbar->setStyleSheet(QStringLiteral("background-color: rgb(246, 246, 246);"));
        user_off = new QToolButton(toolbar);
        user_off->setObjectName(QStringLiteral("user_off"));
        user_off->setGeometry(QRect(6, 45, 45, 45));
        QFont font1;
        font1.setPointSize(1);
        user_off->setFont(font1);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/user_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        user_off->setIcon(icon);
        user_off->setIconSize(QSize(45, 45));
        user_off->setCheckable(false);
        user_off->setAutoRaise(true);
        todo_off = new QToolButton(toolbar);
        todo_off->setObjectName(QStringLiteral("todo_off"));
        todo_off->setGeometry(QRect(6, 125, 45, 45));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/todo_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        todo_off->setIcon(icon1);
        todo_off->setIconSize(QSize(45, 45));
        todo_off->setAutoRaise(true);
        calendar_off = new QToolButton(toolbar);
        calendar_off->setObjectName(QStringLiteral("calendar_off"));
        calendar_off->setGeometry(QRect(6, 205, 45, 45));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/calendar_off .png"), QSize(), QIcon::Normal, QIcon::Off);
        calendar_off->setIcon(icon2);
        calendar_off->setIconSize(QSize(45, 45));
        calendar_off->setAutoRaise(true);
        count_down_off = new QToolButton(toolbar);
        count_down_off->setObjectName(QStringLiteral("count_down_off"));
        count_down_off->setGeometry(QRect(6, 285, 45, 45));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/count_down_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        count_down_off->setIcon(icon3);
        count_down_off->setIconSize(QSize(45, 45));
        count_down_off->setAutoRaise(true);
        dustbin_off = new QToolButton(toolbar);
        dustbin_off->setObjectName(QStringLiteral("dustbin_off"));
        dustbin_off->setGeometry(QRect(6, 365, 45, 45));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/dustbin_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        dustbin_off->setIcon(icon4);
        dustbin_off->setIconSize(QSize(45, 45));
        dustbin_off->setAutoRaise(true);
        search_off = new QToolButton(toolbar);
        search_off->setObjectName(QStringLiteral("search_off"));
        search_off->setGeometry(QRect(6, 442, 45, 45));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/search_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        search_off->setIcon(icon5);
        search_off->setIconSize(QSize(45, 45));
        search_off->setAutoRaise(true);
        log_off = new QToolButton(toolbar);
        log_off->setObjectName(QStringLiteral("log_off"));
        log_off->setGeometry(QRect(6, 522, 45, 45));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/log_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        log_off->setIcon(icon6);
        log_off->setIconSize(QSize(45, 45));
        log_off->setAutoRaise(true);
        setting_off = new QToolButton(toolbar);
        setting_off->setObjectName(QStringLiteral("setting_off"));
        setting_off->setGeometry(QRect(6, 602, 45, 45));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icon/setting_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        setting_off->setIcon(icon7);
        setting_off->setIconSize(QSize(45, 45));
        setting_off->setAutoRaise(true);
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(60, 0, 300, 975));
        inbox = new QWidget(widget_2);
        inbox->setObjectName(QStringLiteral("inbox"));
        inbox->setGeometry(QRect(0, 0, 300, 70));
        widget_3 = new QWidget(inbox);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 300, 65));
        toolButton = new QToolButton(widget_3);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(35, 14, 30, 30));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icon/inbox_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon8);
        toolButton->setIconSize(QSize(30, 30));
        toolButton->setAutoRaise(true);
        label = new QLabel(widget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(94, 9, 75, 33));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(15);
        label->setFont(font2);
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 22, 51, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        label_2->setFont(font3);
        label_2->setStyleSheet(QStringLiteral("color: rgb(163, 163, 163);"));
        line = new QFrame(inbox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 68, 280, 2));
        line->setStyleSheet(QLatin1String("color: rgb(237, 238, 238);\n"
"background-color: rgb(237, 238, 238);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        working_place = new QWidget(widget_2);
        working_place->setObjectName(QStringLiteral("working_place"));
        working_place->setGeometry(QRect(0, 70, 300, 70));
        working_place->setStyleSheet(QLatin1String("background-color: rgba(246, 246, 246, 125);\n"
"border-radius:10px"));
        widget_6 = new QWidget(working_place);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(0, 0, 300, 65));
        toolButton_2 = new QToolButton(widget_6);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(35, 14, 30, 30));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icon/working_table.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon9);
        toolButton_2->setIconSize(QSize(30, 30));
        toolButton_2->setAutoRaise(true);
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 17, 50, 30));
        label_3->setFont(font2);
        toolButton_3 = new QToolButton(widget_6);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(246, 17, 30, 30));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icon/right_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon10);
        toolButton_3->setIconSize(QSize(30, 30));
        toolButton_3->setAutoRaise(true);
        line_3 = new QFrame(working_place);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(10, 68, 280, 2));
        line_3->setStyleSheet(QLatin1String("color: rgb(237, 238, 238);\n"
"background-color: rgb(237, 238, 238);"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        working_place_2 = new QWidget(widget_2);
        working_place_2->setObjectName(QStringLiteral("working_place_2"));
        working_place_2->setGeometry(QRect(0, 140, 300, 70));
        widget_7 = new QWidget(working_place_2);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(0, 0, 300, 65));
        toolButton_4 = new QToolButton(widget_7);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(35, 14, 30, 30));
        toolButton_4->setIcon(icon9);
        toolButton_4->setIconSize(QSize(30, 30));
        toolButton_4->setAutoRaise(true);
        label_4 = new QLabel(widget_7);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 17, 50, 30));
        label_4->setFont(font2);
        toolButton_5 = new QToolButton(widget_7);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(246, 17, 30, 30));
        toolButton_5->setIcon(icon10);
        toolButton_5->setIconSize(QSize(30, 30));
        toolButton_5->setAutoRaise(true);
        line_4 = new QFrame(working_place_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(10, 68, 280, 2));
        line_4->setStyleSheet(QLatin1String("color: rgb(237, 238, 238);\n"
"background-color: rgb(237, 238, 238);"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        new_workplace = new QWidget(widget_2);
        new_workplace->setObjectName(QStringLiteral("new_workplace"));
        new_workplace->setGeometry(QRect(0, 930, 125, 45));
        toolButton_6 = new QToolButton(new_workplace);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(10, 10, 25, 25));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icon/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon11);
        toolButton_6->setIconSize(QSize(25, 25));
        toolButton_6->setAutoRaise(true);
        label_5 = new QLabel(new_workplace);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 15, 70, 15));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        label_5->setFont(font4);
        label_5->setStyleSheet(QString::fromUtf8("font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(163, 163, 163);"));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(360, 0, 2, 975));
        line_2->setStyleSheet(QLatin1String("background-color: rgb(237, 238, 238);\n"
"border-color: rgb(237, 238, 238);"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(362, 0, 856, 153));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(20, 20, 816, 45));
        push_button = new QToolButton(widget_4);
        push_button->setObjectName(QStringLiteral("push_button"));
        push_button->setGeometry(QRect(0, 7, 30, 30));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icon/push_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        push_button->setIcon(icon12);
        push_button->setIconSize(QSize(30, 30));
        push_button->setAutoRaise(true);
        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 0, 101, 45));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(15);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        label_6->setFont(font5);
        label_6->setStyleSheet(QString::fromUtf8("font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        toolButton_7 = new QToolButton(widget_4);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setGeometry(QRect(766, 7, 30, 30));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/icon/more_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon13);
        toolButton_7->setIconSize(QSize(30, 30));
        toolButton_7->setAutoRaise(true);
        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(30, 85, 800, 40));
        widget_5->setStyleSheet(QLatin1String("background-color: rgb(243, 244, 247);\n"
"border-radius:10px;"));
        plainTextEdit = new QPlainTextEdit(widget_5);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 7, 780, 26));
        plainTextEdit->setStyleSheet(QString::fromUtf8("color: rgb(192, 193, 197);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setFrameShadow(QFrame::Plain);
        plainTextEdit->setLineWidth(0);
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(1216, 0, 2, 975));
        line_5->setStyleSheet(QStringLiteral("background-color: rgb(237, 238, 238);"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(362, 153, 856, 3));
        line_6->setStyleSheet(QStringLiteral("background-color: rgb(237, 238, 238);"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(361, 155, 855, 820));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 855, 820));
        widget_8 = new QWidget(scrollAreaWidgetContents);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        widget_8->setGeometry(QRect(10, 10, 835, 60));
        widget_8->setStyleSheet(QLatin1String("background-color: rgba(208, 233, 252, 125);\n"
"border-radius:10px"));
        toolButton_8 = new QToolButton(widget_8);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setGeometry(QRect(10, 23, 15, 15));
        toolButton_8->setIcon(icon12);
        toolButton_8->setIconSize(QSize(15, 15));
        scrollArea->setWidget(scrollAreaWidgetContents);
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
        toolButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\350\215\211\347\250\277\347\256\261", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "18", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\256\266\345\272\255", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        toolButton_4->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\345\267\245\344\275\234", Q_NULLPTR));
        toolButton_5->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        toolButton_6->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\267\245\344\275\234\345\214\272", Q_NULLPTR));
        push_button->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\345\256\266\345\272\255", Q_NULLPTR));
        toolButton_7->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\344\270\200\344\270\252\345\276\205\345\212\236\344\272\213\351\241\271", Q_NULLPTR));
        toolButton_8->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
