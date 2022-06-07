//
// Created by x on 2022/6/6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CentralWidget.h" resolved

#include "centralwidget.h"
#include "ui_CentralWidget.h"

CentralWidget::CentralWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::CentralWidget) {
    ui->setupUi(this);
}

CentralWidget::~CentralWidget() {
    delete ui;
}
