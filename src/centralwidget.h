//
// Created by x on 2022/6/6.
//

#ifndef GDS9_CENTRALWIDGET_H
#define GDS9_CENTRALWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class CentralWidget; }
QT_END_NAMESPACE

class CentralWidget : public QWidget {
Q_OBJECT

public:
    explicit CentralWidget(QWidget *parent = nullptr);
    ~CentralWidget() override;

    Ui::CentralWidget *ui;
private:
};


#endif //GDS9_CENTRALWIDGET_H
