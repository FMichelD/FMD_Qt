#ifndef FM_PRINCIPAL_H
#define FM_PRINCIPAL_H

#include <QMainWindow>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui { class FMPrincipal; }
QT_END_NAMESPACE

class FMPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    FMPrincipal(QWidget *parent = nullptr);
    ~FMPrincipal();

private:
    Ui::FMPrincipal *ui;
    QIcon *icoClosedLock = new QIcon();
    QIcon *icoOpenedLock = new QIcon();
    bool isUserLogged = false;
    QList<QWidget*> widgetList;
    QString nameCollab;
    QString accessCollab;
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");

    void blockScreen();
    void disableAllWidgets();
    void enableAllWidgets();
    void enableToRegisterOnly();
    void enableToSalespersonUser();
    void enableToAdministrator();
    void newSale();
    void stockManagement();
    void employeeManagement();

    void messageBoxTestButtons();
};
#endif // FMPrincipal_H
