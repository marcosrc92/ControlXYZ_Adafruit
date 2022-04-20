#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#define D_motriz_um 20000

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "App_escritorio_6ejes_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}

void conv_movimiento_a_byte(long int avance, char* byte_alto_avance, char* byte_bajo_avance){

    long int pulsos = 27648*avance/D_motriz_um;

    *byte_alto_avance = pulsos/256;
    *byte_bajo_avance = pulsos%256;

    return;
}
