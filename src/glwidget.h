//
// Created by x on 2022/6/21.
//

#ifndef GDS9_GLWIDGET_H
#define GDS9_GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
Q_OBJECT
public:
    GLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent) {}

protected:
    void initializeGL() override;

    void resizeGL(int w, int h) override;

    void paintGL() override;
};




#endif //GDS9_GLWIDGET_H
