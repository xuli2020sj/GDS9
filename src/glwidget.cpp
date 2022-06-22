//
// Created by x on 2022/6/21.
//

#include "glwidget.h"

void GLWidget::initializeGL() {

    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

    // 设置深度缓存
    glClearDepth(1.0);
    // 启用深度测试
    glEnable(GL_DEPTH_TEST);
    // 所作深度测试的类型
    glDepthFunc(GL_LEQUAL);
    // 告诉系统对透视进行修正
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    // 启用2D纹理映射
    glEnable(GL_TEXTURE_2D);
    // 加载纹理
}

void GLWidget::resizeGL(int w, int h) {

}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

}