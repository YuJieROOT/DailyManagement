#include "calendarPage.h"
#include "database.h"

#include <QApplication>
#include <QFontDatabase>
#include <QString>
#include <QFile>
#include <QDebug>

//bool onLoadFont(QString strPath);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QString fontpath = ":/font/微软雅黑.ttf";
    //qDebug() << onLoadFont(fontpath);
    //加载字体
    QFontDatabase::addApplicationFont(":/font/微软雅黑.ttf");
    QFontDatabase::addApplicationFont(":/font/SimSun.ttf");
    QFontDatabase::addApplicationFont(":/font/华文琥珀.ttf");
    //连接数据库
    dataBase *d = new dataBase;
    qDebug() << d->connect("sa", "dq@Zcz5@KK2finh");
    //打开主界面 日历界面
    calendarPage *w = new calendarPage;
    w->getDB(d);
    w->show();

    return a.exec();
}
/*
bool onLoadFont(QString strPath)
{
    QFile dFontFile(strPath);
    if(!dFontFile.open(QIODevice::ReadOnly))
    {
        qDebug()<<"0";
        //说明打开字体文件失败了
        return false;
    }

    int nFontId = QFontDatabase::addApplicationFontFromData(dFontFile.readAll());
    if(nFontId == -1)
    {
        qDebug()<<"1";
        //说明加载字体文件失败了，该字体不可用
        return false;
    }

    QStringList lFontFamily = QFontDatabase::applicationFontFamilies(nFontId);
    if(lFontFamily.empty())
    {
        qDebug()<<"2";
        //说明从字体中获取字体簇失败了
        return false;
    }

    QFont font(lFontFamily.at(0));
    qApp->setFont(font);
    return true;
}
*/
