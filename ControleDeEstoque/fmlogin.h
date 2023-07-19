#ifndef FMLOGIN_H
#define FMLOGIN_H

#include "DBConnection.h"

#include <QDialog>

namespace Ui {
class FMLogin;
}

class FMLogin : public QDialog
{
    Q_OBJECT

public:
    explicit FMLogin(QWidget *parent = nullptr);
    ~FMLogin();

    QString getCollabName();
    QString getCollabAccessLevel();
    bool getIsLogged();

private:
    Ui::FMLogin *ui;
    DBConnection conn;

    QString collabName;
    QString collabAccessLevel;
    bool isLogged = false;

    void login();
};

#endif // FMLOGIN_H
