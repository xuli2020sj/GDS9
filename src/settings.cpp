//
// Created by x on 2022/6/6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_settings.h" resolved

#include "settings.h"
#include "ui_settings.h"
#include "spdlog/fmt/ostr.h"

settings::settings(QWidget *parent) :
        QWidget(parent), ui(new Ui::settings) {
    ui->setupUi(this);
    spdlog::info("setting window object created");
    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton *)), this, SLOT(buttonBoxClicked()));
}

settings::~settings() {
    delete ui;
}

/**
 * 1. 发送设置完成信号
 * 2. 读取设置信息
 * 2. 关闭设置窗口
 */
void settings::buttonBoxClicked() {
    emit settingDone(true);
    readMeasureInfo();
    this->close();
}

void settings::readMeasureInfo() {
    xLen = stod(ui->lineEdit_XLen->text().toStdString());
    yLen = stod(ui->lineEdit_YLen->text().toStdString());
    zLen = stod(ui->lineEdit_ZLen->text().toStdString());
    splitX = splitStr(ui->lineEdit_XSplit->text().toStdString(), ',');
    splitY = splitStr(ui->lineEdit_YSplit->text().toStdString(), ',');
    splitZ = splitStr(ui->lineEdit_ZSplit->text().toStdString(), ',');
    detYPosList = splitStr(ui->lineEdit_DecDistance->text().toStdString(), ',');
    spdlog::trace("Len: {0} {1} {2}", xLen, yLen, zLen);
    spdlog::trace("Len: {0}| {1}| {2}", ui->lineEdit_XSplit->text().toStdString(),
                  ui->lineEdit_YSplit->text().toStdString(),
                  ui->lineEdit_ZSplit->text().toStdString());
}

std::vector<double> settings::splitStr(const std::string& str, char delimiter) {
    std::vector<double> res;
    std::stringstream input(str);
    std::string temp;
    while (std::getline(input, temp, delimiter)) {
        res.push_back(std::stod(temp));
    }
    return res;
}
