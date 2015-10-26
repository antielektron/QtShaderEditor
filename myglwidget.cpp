#include "myglwidget.h"
#include <iostream>




MyGLWidget::MyGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    //nothing to do here!
    this->shaderProg = nullptr;

    QSurfaceFormat format;
    format.setMajorVersion(3);
    format.setMinorVersion(0);
    this->setFormat(format);
}

//=============================================================================

MyGLWidget::~MyGLWidget()
{
    cleanup();
}

//=============================================================================

void MyGLWidget::cleanup()
{
    makeCurrent();
    if (shaderProg)
    {
        delete shaderProg;
    }
    shaderProg = nullptr;
    doneCurrent();
}

//=============================================================================

void MyGLWidget::initializeGL()
{
    connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &MyGLWidget::cleanup);

    glClearColor(0,0,0,1);

    shaderProg = new QOpenGLShaderProgram();

    if (!shaderProg->addShaderFromSourceCode(QOpenGLShader::Vertex, defaultVertexShader))
    {
        std::cerr << "Error while loading Vertex Shader" << std::endl;
    }

    if (!shaderProg->addShaderFromSourceCode(QOpenGLShader::Fragment, defaultFragmentShader))
    {
        std::cerr << "Error while loading Fragment shader" << std::endl;
    }


    shaderProg->bindAttributeLocation("position",0);
    if (!shaderProg->link())
    {
        std::cerr << "Error while linking shader Program!" << std::endl;
    }

    shaderProg->bind();

    mvMatrixLoc = shaderProg->uniformLocation("mvpMatrix");

    //setup vao:
    m_vao.create();
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

    //setup vbo
    m_vbo.create();
    m_vbo.bind();
    //allocate 6 vertices for a quad:
    m_vbo.allocate(defaultQuad.data(), 6 * 3 * sizeof(GLfloat));

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    //fill with data:
    f->glEnableVertexAttribArray(0);
    f->glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

    m_vbo.release();

    m_camera.setToIdentity();
    m_camera.translate(0,0,-1);

    shaderProg->release();

    //debug info:
    auto version = context()->format().version();
    std::cout << "Using OpenGL Version " << version.first << "." << version.second << std::endl;

}

//=============================================================================

void MyGLWidget::resizeGL(int width, int height)
{
    m_proj.setToIdentity();
    m_proj.perspective(45.0f, GLfloat(width) / height, 0.01f, 100.0f);
}

//=============================================================================

void MyGLWidget::paintGL()
{
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    shaderProg->bind();
    m_vbo.bind();


    f->glDrawArrays(GL_TRIANGLES,0,6);
}

//=============================================================================

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50,50);
}

//=============================================================================

QSize MyGLWidget::sizeHint() const
{
    return QSize(400,400);
}

