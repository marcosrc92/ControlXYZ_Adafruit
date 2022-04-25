#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


void conv_movimiento_a_byte(long int, char*, char*);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_B_stepforwX1_clicked();

    void on_B_stepbackX1_clicked();

    void on_B_forwX1_clicked();

    void on_B_backX1_clicked();

    void on_B_comm_clicked();

    void on_B_stepforwY1_clicked();

    void on_B_stepbackY1_clicked();

    void on_B_forwY1_clicked();

    void on_B_backY1_clicked();

    void on_B_stepforwZ1_clicked();

    void on_B_stepbackZ1_clicked();

    void on_B_forwZ1_clicked();

    void on_B_backZ1_clicked();

    void on_B_stepforwX2_clicked();

    void on_B_stepbackX2_clicked();

    void on_B_forwX2_clicked();

    void on_B_backX2_clicked();

    void on_B_stepforwY2_clicked();

    void on_B_stepbackY2_clicked();

    void on_B_forwY2_clicked();

    void on_B_backY2_clicked();

    void on_B_stepforwZ2_clicked();

    void on_B_stepbackZ2_clicked();

    void on_B_forwZ2_clicked();

    void on_B_backZ2_clicked();

private slots:
    void on_B_comm_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

