//
// Created by x on 2022/6/20.
//

#ifndef GDS9_OPENGLWINDOW_H
#define GDS9_OPENGLWINDOW_H

#include <QWidget>
#include "QtOpenGLWidgets/QOpenGLWidget"

QT_BEGIN_NAMESPACE
namespace Ui { class openglwindow; }
QT_END_NAMESPACE

class openglwindow : public QWidget {
Q_OBJECT

public:
    explicit openglwindow(QWidget *parent = nullptr);

    ~openglwindow() override;

private:
    Ui::openglwindow *ui;
};


#endif //GDS9_OPENGLWINDOW_H
