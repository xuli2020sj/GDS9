//
// Created by x on 2022/6/4.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "spdlog/spdlog.h"

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    spdlog::error("Some error message with arg: {}", 1);
}

MainWindow::~MainWindow() {
    delete ui;
}

