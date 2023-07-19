#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QMessageBox>

class DBConnection {

public:
    DBConnection() {
        database = QSqlDatabase::addDatabase("QSQLITE");
    }

    void close() {
        database.close();
    }

    bool open() {
        QString applicationPath = qApp->applicationDirPath();
        QString databasePath = applicationPath + "/../ControleDeEstoque/db/StockControl.db";
        database.setDatabaseName(databasePath);
        if(!database.open())
        {
            QMessageBox::warning(NULL, "Banco de Dados",
                "Falha ao conectar com o Banco de Dados:\n" + databasePath);
            return false;
        }
        return true;
    }

    QSqlDatabase database;
};

#endif // DBCONNECTION_H
