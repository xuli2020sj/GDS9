#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"
#include "spdlog/spdlog.h"
#include "glwidget.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    spdlog::set_level(spdlog::level::trace);
    spdlog::debug("Program Start");

    GLWidget glWidget;
    glWidget.show();

    MainWindow mw;
    mw.show();
    return QApplication::exec();
}
