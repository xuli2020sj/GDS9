//
// Created by x on 2022/6/14.
//

#ifndef GDS9_DATAACQSETTINGWINDOW_H
#define GDS9_DATAACQSETTINGWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class DataAcqSettingWindow; }
QT_END_NAMESPACE

class DataAcqSettingWindow : public QWidget {
Q_OBJECT

public:
    explicit DataAcqSettingWindow(QWidget *parent = nullptr);
    ~DataAcqSettingWindow() override;

private:
    Ui::DataAcqSettingWindow *ui;
};


#endif //GDS9_DATAACQSETTINGWINDOW_H
