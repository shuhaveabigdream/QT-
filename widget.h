#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "hero.h"
#include "commdata.h"



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    QTimer*real_time_fresh;
    ~Widget();

private slots:
    void fresh();
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
