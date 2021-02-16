#include "ui_logic.h"
#include <QLabel>
#include <QVariant>
#include <QDebug>
#include <QToolButton>

void initUI(QWidget *w)
{
    w->setStyleSheet(
                "QScrollArea{"
                    "border: 0px solid;"
                    "border-right-width: 1px;"
                    "border-right-color: #dcdbdc;"
                //    "background-color: #f5f5f7;"
                "background-color: #ffffff;"
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

void initDetailedBar(QWidget *w)
{
    QLabel *inital_pix = w->findChild<QLabel*>("inital_pix");
    if(inital_pix==NULL)
    {
        //第四栏初始化
        inital_pix = new QLabel(w);
        inital_pix->setProperty("objectName","inital_pix");
        inital_pix->setPixmap(QPixmap(":/icon/inital.png"));
        inital_pix->setScaledContents(true);
        inital_pix->setGeometry(0,0,274,675);
        inital_pix->show();
        qDebug()<<inital_pix;
    }
}

