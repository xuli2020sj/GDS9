#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"
#include "spdlog/spdlog.h"
#include <Eigen/Dense>



int main(int argc, char *argv[]) {
    Eigen::MatrixXd m(2,2);
    QApplication a(argc, argv);
    MainWindow mw;
    mw.show();
    spdlog::info("hello");
    return QApplication::exec();
}
