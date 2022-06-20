//
// Created by x on 2022/6/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_openglwindow.h" resolved

#include "openglwindow.h"
#include "ui_openglwindow.h"


openglwindow::openglwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::openglwindow) {
    ui->setupUi(this);
}

openglwindow::~openglwindow() {
    delete ui;
}
