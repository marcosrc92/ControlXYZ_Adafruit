#include "mainwindow.h"
#include "ui_mainwindow.h"

QString comm_port,X1_Qval, X2_Qval, Y1_Qval, Y2_Qval, Z1_Qval, Z2_Qval;
QSerialPort serial;

char msg[6];
char byte_alto_avance, byte_bajo_avance;
long int X1_val, X2_val, Y1_val, Y2_val, Z1_val, Z2_val;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/******************** HMI ************************/

void MainWindow::on_B_comm_clicked()
{
    comm_port = ui->text_comm->toPlainText();
    serial.setPortName(comm_port);
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    if(!serial.open(QIODevice::ReadWrite)){
        QString text = "Can not open communication  port";
        QMessageBox::information(this, "Error Message", text, QMessageBox::Ok);
    }
}


/********************EJE X1************************/

void MainWindow::on_B_stepforwX1_clicked()
{
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_stepbackX1_clicked()
{
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_forwX1_clicked()
{

    X1_Qval = ui->text_X1->toPlainText();
    X1_val = X1_Qval.toInt();

    //convertir de micrometros a pulsos motor
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(X1_val, &byte_alto_avance, &byte_bajo_avance);

    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x01;                  //forward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    int a = serial.write(msg);
}


void MainWindow::on_B_backX1_clicked()
{
    X1_Qval = ui->text_X1->toPlainText();
    X1_val = X1_Qval.toInt();

    //convertir de micrometros a pulsos
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(X1_val, &byte_alto_avance, &byte_bajo_avance);
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    serial.write(msg);
}


/********************EJE Y1************************/

void MainWindow::on_B_stepforwY1_clicked()
{
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_stepbackY1_clicked()
{
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_forwY1_clicked()
{
    Y1_Qval = ui->text_Y1->toPlainText();
    Y1_val = Y1_Qval.toInt();

    //convertir de micrometros a pulsos
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(Y1_val, &byte_alto_avance, &byte_bajo_avance);
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x01;                  //forward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    serial.write(msg);
}


void MainWindow::on_B_backY1_clicked()
{
    Y1_Qval = ui->text_Y1->toPlainText();
    Y1_val = Y1_Qval.toInt();

    //convertir de micrometros a pulsos
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(Y1_val, &byte_alto_avance, &byte_bajo_avance);
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    serial.write(msg);
}


/********************EJE Z1************************/

void MainWindow::on_B_stepforwZ1_clicked()
{
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_stepbackZ1_clicked()
{
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_forwZ1_clicked()
{
    Z1_Qval = ui->text_Z1->toPlainText();
    Z1_val = Z1_Qval.toInt();

    //convertir de micrometros a pulsos
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(Z1_val, &byte_alto_avance, &byte_bajo_avance);
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x01;                  //forward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    serial.write(msg);
}


void MainWindow::on_B_backZ1_clicked()
{
    Z1_Qval = ui->text_Z1->toPlainText();
    Z1_val = Z1_Qval.toInt();

    //convertir de micrometros a pulsos
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(Y1_val, &byte_alto_avance, &byte_bajo_avance);
    msg[0] = 0x62;                  //driver address z
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    serial.write(msg);
}


/********************EJE X2************************/

void MainWindow::on_B_stepforwX2_clicked()
{
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_stepbackX2_clicked()
{
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x02;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_forwX2_clicked()
{
    X2_Qval = ui->text_X2->toPlainText();
    X2_val = X2_Qval.toInt();

    //convertir de micrometros a pulsos
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(X2_val, &byte_alto_avance, &byte_bajo_avance);
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    serial.write(msg);
}


void MainWindow::on_B_backX2_clicked()
{
    X2_Qval = ui->text_X2->toPlainText();
    X2_val = X2_Qval.toInt();

    //convertir de micrometros a pulsos
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(X2_val, &byte_alto_avance, &byte_bajo_avance);
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x02;                  //backward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    serial.write(msg);
}


/********************EJE Y2************************/

void MainWindow::on_B_stepforwY2_clicked()
{
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_stepbackY2_clicked()
{
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x02;                  //BACKward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_forwY2_clicked()
{
    Y2_Qval = ui->text_Y2->toPlainText();
    Y2_val = Y2_Qval.toInt();

    //convertir de micrometros a pulsos
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(Y2_val, &byte_alto_avance, &byte_bajo_avance);
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    serial.write(msg);
}


void MainWindow::on_B_backY2_clicked()
{
    Y2_Qval = ui->text_Y2->toPlainText();
    Y2_val = Y2_Qval.toInt();

    //convertir de micrometros a pulsos
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(Y2_val, &byte_alto_avance, &byte_bajo_avance);
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x02;                  //backward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    serial.write(msg);
}


/********************EJE Z2************************/

void MainWindow::on_B_stepforwZ2_clicked()
{
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_stepbackZ2_clicked()
{
    msg[0] = 0x62;                  //driver address Y
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg);
}


void MainWindow::on_B_forwZ2_clicked()
{
    Z2_Qval = ui->text_Z2->toPlainText();
    Z2_val = Z2_Qval.toInt();

    //convertir de micrometros a pulsos
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(Z2_val, &byte_alto_avance, &byte_bajo_avance);
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    serial.write(msg);
}


void MainWindow::on_B_backZ2_clicked()
{
    Z2_Qval = ui->text_Z2->toPlainText();
    Z2_val = Z2_Qval.toInt();

    //convertir de micrometros a pulsos
    //convertir numero de pulsos a 2 bytes
    conv_movimiento_a_byte(Z2_val, &byte_alto_avance, &byte_bajo_avance);
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x02;                  //backward
    msg[3] = 0x03;                  //interleave
    msg[4] = byte_alto_avance;
    msg[5] = byte_bajo_avance;

    serial.write(msg);
}

