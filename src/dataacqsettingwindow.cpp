//
// Created by x on 2022/6/14.
//

// You may need to build the project (run Qt uic code generator) to get "ui_DataAcqSettingWindow.h" resolved

#include "dataacqsettingwindow.h"
#include "ui_DataAcqSettingWindow.h"


DataAcqSettingWindow::DataAcqSettingWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::DataAcqSettingWindow) {
    ui->setupUi(this);

}

DataAcqSettingWindow::~DataAcqSettingWindow() {
    delete ui;
}
