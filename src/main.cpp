#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"
#include "spdlog/spdlog.h"



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    spdlog::info("Program Start");
    MainWindow mw;
    mw.show();
    return QApplication::exec();
}
