//
// Created by x on 2022/6/6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "centralwidget.h"
#include "ui_CentralWidget.h"
#include "settings.h"
#include "spdlog/spdlog.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    uiCentral = new CentralWidget(this);
    this->setCentralWidget(uiCentral);
    connect(ui->actionMeasureSetting, SIGNAL(triggered()), this, SLOT(openSettingWin()));

}

MainWindow::~MainWindow() {
    delete ui;
    delete uiSettings;
    delete uiCentral;
}

void MainWindow::openSettingWin() {
    if (uiSettings == nullptr) {
        uiSettings = new settings();
        connect(uiSettings, SIGNAL(settingDone(bool)), this, SLOT(initReconstruction()));
    }
    uiSettings->show();
}


void MainWindow::initReconstruction() {
    uiCentral->ui->pushButtonReconstruction->setEnabled(true);
}
