#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Figures.h"

enum EditMode{
    Draw,
    Move,
    Rotate,
    Scale
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void DisplayCharacteristics();
    void ClearCanva();

private slots:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

    void on_ButMove_clicked();
    //void on_ButPaint_clicked();
    //void on_FigureSelecter_currentIndexChanged(int index);
    void on_ButScale_clicked();
    void on_ButRotate_clicked();

    void on_ButClear_clicked();

    void on_ButRotAntiClockWise_pressed();

    void on_ButRotAntiClockWise_released();


    void RotateForButtonClock(){
        m_pCurrentFigure->Rotate(1);
        DisplayCharacteristics();
        update();
    }
    void RotateForButtonAntiClock(){
        m_pCurrentFigure->Rotate(-1);
        DisplayCharacteristics();
        update();
    }
    void SizeIncrease(){
        m_pCurrentFigure->Scale(false);
        DisplayCharacteristics();
        update();
    }
    void SizeDecrease(){
        m_pCurrentFigure->Scale(true);
        DisplayCharacteristics();
        update();
    }

    void MoveUp(){
        m_pCurrentFigure->Translate(0.0f, 1.0f);
        update();
    }
    void MoveDown(){
        m_pCurrentFigure->Translate(0.0f, -1.0f);
        update();
    }
    void MoveRight(){
        m_pCurrentFigure->Translate(-1.0f, 0.0f);
        update();
    }
    void MoveLeft(){
        m_pCurrentFigure->Translate(1.0f, 0.0f);
        update();
    }

    void on_FigureSelecter_activated(int index);

    void on_ButRotClockWise_pressed();

    void on_ButRotClockWise_released();

    void on_ButScaleR_pressed();

    void on_ButScaleR_released();

    void on_ButScaleL_pressed();

    void on_ButScaleL_released();

    void on_ButMoveRight_pressed();


    void on_ButMoveRight_released();

    void on_ButMoveLeft_pressed();

    void on_ButMoveLeft_released();

    void on_ButMoveUp_released();

    void on_ButMoveUp_pressed();

    void on_ButMoveDown_pressed();

    void on_ButMoveDown_released();

private:
    Ui::MainWindow *ui;

    EditMode m_currentEditMode = Draw;
    IFigure* m_pCurrentFigure;
    QTimer m_timer = QTimer();
};
#endif // MAINWINDOW_H
