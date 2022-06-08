//
// Created by x on 2022/6/6.
//

#ifndef GDS9_SETTINGS_H
#define GDS9_SETTINGS_H

#include <QWidget>
#include "spdlog/spdlog.h"
#include <sstream>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class settings; }
QT_END_NAMESPACE

class settings : public QWidget {
Q_OBJECT

signals:
    void settingDone(bool flag);

public slots:
    void buttonBoxClicked();

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings() override;

    double xLen = 0., yLen = 0., zLen = 0.;
    std::vector<double> splitX;
    std::vector<double> splitY;
    std::vector<double> splitZ;
    std::vector<double> detYPosList;

private:
    Ui::settings *ui;
    void readMeasureInfo();
    static std::vector<double> splitStr(const std::string& str, char delimiter);



};


#endif //GDS9_SETTINGS_H
