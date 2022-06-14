//
// Created by x on 2022/6/6.
//

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "centralwidget.h"
#include "ui_CentralWidget.h"
#include "settings.h"
#include "spdlog/spdlog.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    controller = &controller::getController();
    uiCentral = new CentralWidget(this);
    this->setCentralWidget(uiCentral);

    connect(ui->actionMeasureSetting, SIGNAL(triggered()), this, SLOT(openSettingWin()));
    connect(ui->actionDataAcqSetting, SIGNAL(triggered()), this, SLOT(openDataAcqSettingWin()));
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
    controller->initReconstruction();
    controller->startReconstruction();
}

void MainWindow::openDataAcqSettingWin() {
    if (uiDataAcqSettings == nullptr) {
        uiDataAcqSettings = new DataAcqSettingWindow();
//        connect(uiSettings, SIGNAL(settingDone(bool)), this, SLOT(initReconstruction()));
    }
    uiDataAcqSettings->show();
}


