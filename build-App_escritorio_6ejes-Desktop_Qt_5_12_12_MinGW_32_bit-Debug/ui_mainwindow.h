/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_3;
    QPushButton *B_stepforwX1;
    QPushButton *B_stepbackX1;
    QPushButton *B_backX1;
    QPushButton *B_forwX1;
    QLabel *img_lens1;
    QTextEdit *text_X1;
    QPushButton *B_forwZ1;
    QTextEdit *text_Z1;
    QPushButton *B_stepbackZ1;
    QPushButton *B_stepforwZ1;
    QPushButton *B_backZ1;
    QLabel *label_5;
    QPushButton *B_forwY1;
    QTextEdit *text_Y1;
    QPushButton *B_stepbackY1;
    QPushButton *B_stepforwY1;
    QPushButton *B_backY1;
    QLabel *label_6;
    QPushButton *B_stepforwX2;
    QLabel *label_7;
    QPushButton *B_backX2;
    QLabel *label_8;
    QTextEdit *text_X2;
    QPushButton *B_forwY2;
    QPushButton *B_backZ2;
    QPushButton *B_forwX2;
    QLabel *label_9;
    QLabel *img_lens1_2;
    QPushButton *B_stepforwY2;
    QTextEdit *text_Z2;
    QPushButton *B_forwZ2;
    QPushButton *B_stepforwZ2;
    QPushButton *B_stepbackZ2;
    QPushButton *B_backY2;
    QTextEdit *text_Y2;
    QLabel *label_10;
    QPushButton *B_stepbackX2;
    QPushButton *B_stepbackY2;
    QLabel *label_11;
    QTextEdit *text_comm;
    QPushButton *B_comm;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1389, 691);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 120, 191, 41));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 440, 71, 31));
        QFont font1;
        font1.setPointSize(14);
        label_3->setFont(font1);
        B_stepforwX1 = new QPushButton(centralwidget);
        B_stepforwX1->setObjectName(QString::fromUtf8("B_stepforwX1"));
        B_stepforwX1->setGeometry(QRect(210, 524, 121, 28));
        B_stepbackX1 = new QPushButton(centralwidget);
        B_stepbackX1->setObjectName(QString::fromUtf8("B_stepbackX1"));
        B_stepbackX1->setGeometry(QRect(100, 524, 111, 28));
        B_backX1 = new QPushButton(centralwidget);
        B_backX1->setObjectName(QString::fromUtf8("B_backX1"));
        B_backX1->setGeometry(QRect(100, 470, 41, 41));
        B_forwX1 = new QPushButton(centralwidget);
        B_forwX1->setObjectName(QString::fromUtf8("B_forwX1"));
        B_forwX1->setGeometry(QRect(290, 470, 41, 41));
        img_lens1 = new QLabel(centralwidget);
        img_lens1->setObjectName(QString::fromUtf8("img_lens1"));
        img_lens1->setGeometry(QRect(170, 170, 391, 361));
        img_lens1->setPixmap(QPixmap(QString::fromUtf8("../8305_RBL13D_SGL.jpg")));
        img_lens1->setScaledContents(true);
        text_X1 = new QTextEdit(centralwidget);
        text_X1->setObjectName(QString::fromUtf8("text_X1"));
        text_X1->setGeometry(QRect(150, 470, 131, 41));
        QFont font2;
        font2.setPointSize(12);
        text_X1->setFont(font2);
        B_forwZ1 = new QPushButton(centralwidget);
        B_forwZ1->setObjectName(QString::fromUtf8("B_forwZ1"));
        B_forwZ1->setGeometry(QRect(240, 140, 41, 41));
        text_Z1 = new QTextEdit(centralwidget);
        text_Z1->setObjectName(QString::fromUtf8("text_Z1"));
        text_Z1->setGeometry(QRect(100, 140, 131, 41));
        text_Z1->setFont(font2);
        B_stepbackZ1 = new QPushButton(centralwidget);
        B_stepbackZ1->setObjectName(QString::fromUtf8("B_stepbackZ1"));
        B_stepbackZ1->setGeometry(QRect(50, 190, 111, 28));
        B_stepforwZ1 = new QPushButton(centralwidget);
        B_stepforwZ1->setObjectName(QString::fromUtf8("B_stepforwZ1"));
        B_stepforwZ1->setGeometry(QRect(160, 190, 121, 28));
        B_backZ1 = new QPushButton(centralwidget);
        B_backZ1->setObjectName(QString::fromUtf8("B_backZ1"));
        B_backZ1->setGeometry(QRect(50, 140, 41, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 110, 71, 31));
        label_5->setFont(font1);
        B_forwY1 = new QPushButton(centralwidget);
        B_forwY1->setObjectName(QString::fromUtf8("B_forwY1"));
        B_forwY1->setGeometry(QRect(680, 380, 41, 41));
        text_Y1 = new QTextEdit(centralwidget);
        text_Y1->setObjectName(QString::fromUtf8("text_Y1"));
        text_Y1->setGeometry(QRect(540, 380, 131, 41));
        text_Y1->setFont(font2);
        B_stepbackY1 = new QPushButton(centralwidget);
        B_stepbackY1->setObjectName(QString::fromUtf8("B_stepbackY1"));
        B_stepbackY1->setGeometry(QRect(490, 430, 111, 28));
        B_stepforwY1 = new QPushButton(centralwidget);
        B_stepforwY1->setObjectName(QString::fromUtf8("B_stepforwY1"));
        B_stepforwY1->setGeometry(QRect(600, 430, 121, 28));
        B_backY1 = new QPushButton(centralwidget);
        B_backY1->setObjectName(QString::fromUtf8("B_backY1"));
        B_backY1->setGeometry(QRect(490, 380, 41, 41));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(580, 350, 71, 31));
        label_6->setFont(font1);
        B_stepforwX2 = new QPushButton(centralwidget);
        B_stepforwX2->setObjectName(QString::fromUtf8("B_stepforwX2"));
        B_stepforwX2->setGeometry(QRect(870, 524, 121, 28));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(960, 120, 191, 41));
        label_7->setFont(font);
        B_backX2 = new QPushButton(centralwidget);
        B_backX2->setObjectName(QString::fromUtf8("B_backX2"));
        B_backX2->setGeometry(QRect(760, 470, 41, 41));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1230, 350, 71, 31));
        label_8->setFont(font1);
        text_X2 = new QTextEdit(centralwidget);
        text_X2->setObjectName(QString::fromUtf8("text_X2"));
        text_X2->setGeometry(QRect(810, 470, 131, 41));
        text_X2->setFont(font2);
        B_forwY2 = new QPushButton(centralwidget);
        B_forwY2->setObjectName(QString::fromUtf8("B_forwY2"));
        B_forwY2->setGeometry(QRect(1340, 380, 41, 41));
        B_backZ2 = new QPushButton(centralwidget);
        B_backZ2->setObjectName(QString::fromUtf8("B_backZ2"));
        B_backZ2->setGeometry(QRect(710, 140, 41, 41));
        B_forwX2 = new QPushButton(centralwidget);
        B_forwX2->setObjectName(QString::fromUtf8("B_forwX2"));
        B_forwX2->setGeometry(QRect(950, 470, 41, 41));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(800, 110, 71, 31));
        label_9->setFont(font1);
        img_lens1_2 = new QLabel(centralwidget);
        img_lens1_2->setObjectName(QString::fromUtf8("img_lens1_2"));
        img_lens1_2->setGeometry(QRect(830, 170, 391, 361));
        img_lens1_2->setPixmap(QPixmap(QString::fromUtf8("../8305_RBL13D_SGL.jpg")));
        img_lens1_2->setScaledContents(true);
        B_stepforwY2 = new QPushButton(centralwidget);
        B_stepforwY2->setObjectName(QString::fromUtf8("B_stepforwY2"));
        B_stepforwY2->setGeometry(QRect(1260, 430, 121, 28));
        text_Z2 = new QTextEdit(centralwidget);
        text_Z2->setObjectName(QString::fromUtf8("text_Z2"));
        text_Z2->setGeometry(QRect(760, 140, 131, 41));
        text_Z2->setFont(font2);
        B_forwZ2 = new QPushButton(centralwidget);
        B_forwZ2->setObjectName(QString::fromUtf8("B_forwZ2"));
        B_forwZ2->setGeometry(QRect(900, 140, 41, 41));
        B_stepforwZ2 = new QPushButton(centralwidget);
        B_stepforwZ2->setObjectName(QString::fromUtf8("B_stepforwZ2"));
        B_stepforwZ2->setGeometry(QRect(820, 190, 121, 28));
        B_stepbackZ2 = new QPushButton(centralwidget);
        B_stepbackZ2->setObjectName(QString::fromUtf8("B_stepbackZ2"));
        B_stepbackZ2->setGeometry(QRect(710, 190, 111, 28));
        B_backY2 = new QPushButton(centralwidget);
        B_backY2->setObjectName(QString::fromUtf8("B_backY2"));
        B_backY2->setGeometry(QRect(1150, 380, 41, 41));
        text_Y2 = new QTextEdit(centralwidget);
        text_Y2->setObjectName(QString::fromUtf8("text_Y2"));
        text_Y2->setGeometry(QRect(1200, 380, 131, 41));
        text_Y2->setFont(font2);
        text_Y2->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(850, 440, 71, 31));
        label_10->setFont(font1);
        B_stepbackX2 = new QPushButton(centralwidget);
        B_stepbackX2->setObjectName(QString::fromUtf8("B_stepbackX2"));
        B_stepbackX2->setGeometry(QRect(760, 524, 111, 28));
        B_stepbackY2 = new QPushButton(centralwidget);
        B_stepbackY2->setObjectName(QString::fromUtf8("B_stepbackY2"));
        B_stepbackY2->setGeometry(QRect(1150, 430, 111, 28));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(590, 10, 121, 31));
        label_11->setFont(font1);
        text_comm = new QTextEdit(centralwidget);
        text_comm->setObjectName(QString::fromUtf8("text_comm"));
        text_comm->setGeometry(QRect(580, 40, 131, 41));
        text_comm->setFont(font2);
        text_comm->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        text_comm->setContextMenuPolicy(Qt::DefaultContextMenu);
        text_comm->setToolTipDuration(-1);
        text_comm->setAutoFillBackground(false);
        text_comm->setOverwriteMode(false);
        B_comm = new QPushButton(centralwidget);
        B_comm->setObjectName(QString::fromUtf8("B_comm"));
        B_comm->setGeometry(QRect(600, 90, 91, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 380, 55, 31));
        label_2->setFont(font2);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(860, 140, 55, 31));
        label_4->setFont(font2);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(1300, 380, 55, 31));
        label_12->setFont(font2);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(910, 470, 55, 31));
        label_14->setFont(font2);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(250, 470, 55, 31));
        label_15->setFont(font2);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(200, 140, 55, 31));
        label_16->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        img_lens1_2->raise();
        img_lens1->raise();
        label->raise();
        label_3->raise();
        B_stepforwX1->raise();
        B_stepbackX1->raise();
        B_backX1->raise();
        B_forwX1->raise();
        text_X1->raise();
        B_forwZ1->raise();
        text_Z1->raise();
        B_stepbackZ1->raise();
        B_stepforwZ1->raise();
        B_backZ1->raise();
        label_5->raise();
        B_forwY1->raise();
        text_Y1->raise();
        B_stepbackY1->raise();
        B_stepforwY1->raise();
        B_backY1->raise();
        label_6->raise();
        B_stepforwX2->raise();
        label_7->raise();
        B_backX2->raise();
        label_8->raise();
        text_X2->raise();
        B_forwY2->raise();
        B_backZ2->raise();
        B_forwX2->raise();
        label_9->raise();
        B_stepforwY2->raise();
        text_Z2->raise();
        B_forwZ2->raise();
        B_stepforwZ2->raise();
        B_stepbackZ2->raise();
        B_backY2->raise();
        text_Y2->raise();
        label_10->raise();
        B_stepbackX2->raise();
        B_stepbackY2->raise();
        label_11->raise();
        text_comm->raise();
        B_comm->raise();
        label_2->raise();
        label_4->raise();
        label_12->raise();
        label_14->raise();
        label_15->raise();
        label_16->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1389, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "LENS 1", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "X Axis", nullptr));
        B_stepforwX1->setText(QApplication::translate("MainWindow", "STEP FORWARD", nullptr));
        B_stepbackX1->setText(QApplication::translate("MainWindow", "STEP BACKWARD", nullptr));
        B_backX1->setText(QApplication::translate("MainWindow", "-", nullptr));
        B_forwX1->setText(QApplication::translate("MainWindow", "+", nullptr));
        B_forwZ1->setText(QApplication::translate("MainWindow", "+", nullptr));
        B_stepbackZ1->setText(QApplication::translate("MainWindow", "STEP BACKWARD", nullptr));
        B_stepforwZ1->setText(QApplication::translate("MainWindow", "STEP FORWARD", nullptr));
        B_backZ1->setText(QApplication::translate("MainWindow", "-", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Z Axis", nullptr));
        B_forwY1->setText(QApplication::translate("MainWindow", "+", nullptr));
        B_stepbackY1->setText(QApplication::translate("MainWindow", "STEP BACKWARD", nullptr));
        B_stepforwY1->setText(QApplication::translate("MainWindow", "STEP FORWARD", nullptr));
        B_backY1->setText(QApplication::translate("MainWindow", "-", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Y Axis", nullptr));
        B_stepforwX2->setText(QApplication::translate("MainWindow", "STEP FORWARD", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "LENS 2", nullptr));
        B_backX2->setText(QApplication::translate("MainWindow", "-", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Y Axis", nullptr));
        B_forwY2->setText(QApplication::translate("MainWindow", "+", nullptr));
        B_backZ2->setText(QApplication::translate("MainWindow", "-", nullptr));
        B_forwX2->setText(QApplication::translate("MainWindow", "+", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Z Axis", nullptr));
        B_stepforwY2->setText(QApplication::translate("MainWindow", "STEP FORWARD", nullptr));
        B_forwZ2->setText(QApplication::translate("MainWindow", "+", nullptr));
        B_stepforwZ2->setText(QApplication::translate("MainWindow", "STEP FORWARD", nullptr));
        B_stepbackZ2->setText(QApplication::translate("MainWindow", "STEP BACKWARD", nullptr));
        B_backY2->setText(QApplication::translate("MainWindow", "-", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "X Axis", nullptr));
        B_stepbackX2->setText(QApplication::translate("MainWindow", "STEP BACKWARD", nullptr));
        B_stepbackY2->setText(QApplication::translate("MainWindow", "STEP BACKWARD", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Comm port", nullptr));
#ifndef QT_NO_TOOLTIP
        text_comm->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_ACCESSIBILITY
        text_comm->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        text_comm->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        text_comm->setDocumentTitle(QString());
        text_comm->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        text_comm->setPlaceholderText(QApplication::translate("MainWindow", "COM0", nullptr));
        B_comm->setText(QApplication::translate("MainWindow", "SET", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\302\265m", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\302\265m", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\302\265m", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\302\265m", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\302\265m", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\302\265m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
