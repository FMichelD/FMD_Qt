#include "FMLogin.h"
#include "ui_FMLogin.h"

#include <QCryptographicHash>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

FMLogin::FMLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FMLogin)
{
    ui->setupUi(this);
    connect(ui->btnLogin, &QPushButton::clicked, this, &FMLogin::login);
}

FMLogin::~FMLogin()
{
    delete ui;
}

void FMLogin::login()
{
    if(conn.open())
    {
        QString userName;
        QString passwordHash;
        userName = ui->edtUserName->text();
        passwordHash = QString(QCryptographicHash::hash(ui->edtPassword->text().toUtf8(),
                QCryptographicHash::Sha256).toHex());

        qDebug() << passwordHash;

        QSqlQuery query;
        query.prepare("select * from tb_collaborators where username_collab='" + userName +
            "' and password_collab='" + passwordHash + "'");
        if(query.exec())
        {
            query.first();
            if(query.value(query.record().indexOf("access_collab")).toString() != "")
            {
                collabName = query.value(query.record().indexOf("name_collab")).toString();
                collabAccessLevel = query.value(query.record().indexOf("access_collab")).toString();
                isLogged = true;
                conn.close();
                close();
            } else {
                isLogged = false;
                QMessageBox::warning(this, "Erro", "Colaborador não encontrado!");
            }
        } else {
            qDebug() << "Falha ao executar a query!";
        }
    }
    conn.close();
}

QString FMLogin::getCollabName()
{
    return collabName;
}

QString FMLogin::getCollabAccessLevel()
{
    return collabAccessLevel;
}

bool FMLogin::getIsLogged()
{
    return isLogged;
}
