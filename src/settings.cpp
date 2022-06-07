//
// Created by x on 2022/6/6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_settings.h" resolved

#include "settings.h"
#include "ui_settings.h"

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
 *
 */
void settings::buttonBoxClicked() {
    emit settingDone(true);
    this->close();

}
