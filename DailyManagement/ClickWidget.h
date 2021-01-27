#ifndef CLICKWIDGET_H
#define CLICKWIDGET_H

#include <QWidget>
#include <QGridLayout>

class ClickWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClickWidget(QWidget *parent = nullptr):
        QWidget(parent)
    {
        //this->setStyleSheet("background: #32CC99;");
        setAttribute(Qt::WA_StyledBackground);
    };
    QString getText();
    void setText(QString);
    //void initWidget();

signals:
    void clicked(ClickWidget *);

protected:
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseDoubleClickEvent(QMouseEvent*);
private:
    QString text;
};

#endif // CLICKWIDGET_H
