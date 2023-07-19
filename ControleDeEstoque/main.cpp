#include "fmprincipal.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ControleDeEstoque_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QDir stylesheetsDir(":/stylesheets");
    QFileInfoList entries = stylesheetsDir.entryInfoList();
    QString completeStylesheet = "";
    foreach (QFileInfo fileInfo, entries)
    {
        QFile file(":/stylesheets/" + fileInfo.fileName());
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
           continue;

        QTextStream in(&file);
        completeStylesheet += in.readAll();
    }

    a.setStyleSheet(completeStylesheet);

    FMPrincipal w;
    w.show();
    return a.exec();
}
