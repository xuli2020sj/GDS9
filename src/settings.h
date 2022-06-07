//
// Created by x on 2022/6/6.
//

#ifndef GDS9_SETTINGS_H
#define GDS9_SETTINGS_H

#include <QWidget>
#include "spdlog/spdlog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class settings; }
QT_END_NAMESPACE

class settings : public QWidget {
Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);

    ~settings() override;

private:
    Ui::settings *ui;

signals:
    void settingDone(bool flag);

public slots:
    void buttonBoxClicked();

};


#endif //GDS9_SETTINGS_H
