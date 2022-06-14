//
// Created by x on 2022/6/6.
//

#ifndef GDS9_MAINWINDOW_H
#define GDS9_MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"
#include "ui_settings.h"
#include "centralwidget.h"
#include "settings.h"

#include "dataacqsettingwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    CentralWidget *uiCentral;
    settings *uiSettings = nullptr;
    controller *controller = nullptr;

    DataAcqSettingWindow *uiDataAcqSettings = nullptr;

public slots:
    void openSettingWin();
    void initReconstruction();
    void openDataAcqSettingWin();
};


#endif //GDS9_MAINWINDOW_H
