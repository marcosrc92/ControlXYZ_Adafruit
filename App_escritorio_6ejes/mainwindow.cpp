#include "mainwindow.h"
#include "ui_mainwindow.h"

#define TAMMSG 6

QString comm_port,X1_Qval, X2_Qval, Y1_Qval, Y2_Qval, Z1_Qval, Z2_Qval;
QSerialPort serial;

char msg[TAMMSG];
char byte_alto_avance, byte_bajo_avance;
long int X1_val, X2_val, Y1_val, Y2_val, Z1_val, Z2_val;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_comm->setStyleSheet("color: red");
    ui->label_comm->setText("Disconnected");


    //shortcuts para LENS 1

    keyW = new QShortcut(this);
    keyW->setKey(Qt::Key_W);
    connect(keyW, SIGNAL(activated()), this, SLOT(slotShortcutW()));

    keyA = new QShortcut(this);
    keyA->setKey(Qt::Key_A);
    connect(keyA, SIGNAL(activated()), this, SLOT(slotShortcutA()));

    keyS = new QShortcut(this);
    keyS->setKey(Qt::Key_S);
    connect(keyS, SIGNAL(activated()), this, SLOT(slotShortcutS()));

    keyD = new QShortcut(this);
    keyD->setKey(Qt::Key_D);
    connect(keyD, SIGNAL(activated()), this, SLOT(slotShortcutD()));

    keyShiftW = new QShortcut(this);
    keyShiftW->setKey(QKeySequence("Shift+W"));
    connect(keyShiftW, SIGNAL(activated()), this, SLOT(slotShortcutShiftW()));

    keyShiftS = new QShortcut(this);
    keyShiftS->setKey(QKeySequence("Shift+S"));
    connect(keyShiftS, SIGNAL(activated()), this, SLOT(slotShortcutShiftS()));


    //shortcuts para LENS 2

    keyUp = new QShortcut(this);
    keyUp->setKey(Qt::Key_Up);
    connect(keyUp, SIGNAL(activated()), this, SLOT(slotShortcutUp()));

    keyDown = new QShortcut(this);
    keyDown->setKey(Qt::Key_Down);
    connect(keyDown, SIGNAL(activated()), this, SLOT(slotShortcutDown()));

    keyLeft = new QShortcut(this);
    keyLeft->setKey(Qt::Key_Left);
    connect(keyLeft, SIGNAL(activated()), this, SLOT(slotShortcutLeft()));

    keyRight = new QShortcut(this);
    keyRight->setKey(Qt::Key_Right);
    connect(keyRight, SIGNAL(activated()), this, SLOT(slotShortcutRight()));

    keyShiftUp = new QShortcut(this);
    keyShiftUp->setKey(QKeySequence("Shift+Up"));
    connect(keyShiftUp, SIGNAL(activated()), this, SLOT(slotShortcutShiftUp()));

    keyShiftDown = new QShortcut(this);
    keyShiftDown->setKey(QKeySequence("Shift+Down"));
    connect(keyShiftDown, SIGNAL(activated()), this, SLOT(slotShortcutShiftDown()));
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
        ui->label_comm->setStyleSheet("color: red");
        ui->label_comm->setText("Disconnected");
        QString text = "Can not open communication port";
        QMessageBox::information(this, "Error Message", text, QMessageBox::Ok);
    }
    else{
        ui->label_comm->setStyleSheet("color: green");
        ui->label_comm->setText("Connected");
    }
}

void MainWindow::on_B_comm_2_clicked()
{
    serial.close();
    if(serial.isOpen()){
        QString text = "Can not close communication port";
        QMessageBox::information(this, "Error Message", text, QMessageBox::Ok);
        ui->label_comm->setStyleSheet("color: green");
        ui->label_comm->setText("Connected");
    }
    else{
        ui->label_comm->setStyleSheet("color: red");
        ui->label_comm->setText("Disconnected");
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

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutD(){
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::on_B_stepbackX1_clicked()
{
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutA(){
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
}


/********************EJE Y1************************/

void MainWindow::on_B_stepforwY1_clicked()
{
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutW(){
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::on_B_stepbackY1_clicked()
{
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutS(){
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
}


/********************EJE Z1************************/

void MainWindow::on_B_stepforwZ1_clicked()
{
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutShiftW(){
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::on_B_stepbackZ1_clicked()
{
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutShiftS(){
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x01;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
}


/********************EJE X2************************/

void MainWindow::on_B_stepforwX2_clicked()
{
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutRight(){
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::on_B_stepbackX2_clicked()
{
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x02;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutLeft(){
    msg[0] = 0x60;                  //driver address X
    msg[1] = 0x02;                  //motor 1
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
}


/********************EJE Y2************************/

void MainWindow::on_B_stepforwY2_clicked()
{
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutUp(){
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::on_B_stepbackY2_clicked()
{
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x02;                  //BACKward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutDown(){
    msg[0] = 0x61;                  //driver address Y
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x02;                  //BACKward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
}


/********************EJE Z2************************/

void MainWindow::on_B_stepforwZ2_clicked()
{
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutShiftUp(){
    msg[0] = 0x62;                  //driver address Z
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x01;                  //forward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::on_B_stepbackZ2_clicked()
{
    msg[0] = 0x62;                  //driver address Y
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
}


void MainWindow::slotShortcutShiftDown(){
    msg[0] = 0x62;                  //driver address Y
    msg[1] = 0x02;                  //motor 2
    msg[2] = 0x02;                  //backward
    msg[3] = 0x04;                  //microsteping
    msg[4] = 0x00;  msg[5] = 0x01;  //1 step

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
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

    serial.write(msg,TAMMSG);
}




