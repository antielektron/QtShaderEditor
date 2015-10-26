#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QObject>
#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

#include <QOpenGLVertexArrayObject>

#include <QString>
#include <vector>

class MyGLWidget : public QOpenGLWidget
{

    Q_OBJECT

public:
    MyGLWidget(QWidget *parent = nullptr);
    ~MyGLWidget();

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    const QString defaultVertexShader =
            "#version 130\n"
            "\n"
            "in vec3 position; \n"
            "\n"
            "uniform mat4 mvpMatrix;\n"
            "\n"
            "void main()\n"
            "{\n"
            "    gl_Position = mvpMatrix * vec4(position, 1.);\n"
            "}\n";

    const QString defaultFragmentShader =
            "#version 130\n"
            "\n"
            "uniform vec4 color;\n"
            "\n"
            "out vec4 outputColor;\n"
            "\n"
            "void main()\n"
            "{\n"
            "   outputColor = vec4(1.,1.,1.,1.); // color;\n"
            "}\n";

    const std::vector<GLfloat> defaultQuad =
        {-0.3f, -0.3f, 0.0f,
         0.3f, -0.3f, 0.0f,
         0.3f, 0.3f, 0.0f,
         0.3f, 0.3f, 0.0f,
         -0.3f, 0.3f, 0.0f,
         -0.3f, -0.3f, 0.0f};

public slots:
    void cleanup();

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;



    QOpenGLShaderProgram* shaderProg;

    QMatrix4x4 m_proj;
    QMatrix4x4 m_world;
    QMatrix4x4 m_camera;

    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo;

    int mvMatrixLoc;

signals:

public slots:
};

#endif // MYGLWIDGET_H
