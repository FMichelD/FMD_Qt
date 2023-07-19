#include "fmprincipal.h"
#include "./ui_fmprincipal.h"
#include "fmlogin.h"
#include "FMNewSale.h"
#include "FMEmployeeManagement.h"
#include "FMStockManagement.h"

#include <QMessageBox>

FMPrincipal::FMPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FMPrincipal)
{
    ui->setupUi(this);
    icoOpenedLock->addFile(":/Imagens/OpenedLock.png");
    icoClosedLock->addFile(":/Imagens/ClosedLock.png");

    ui->btnLock->setText("");
    ui->btnLock->setIcon(*icoClosedLock);
    ui->statusbar->addWidget(ui->btnLock);
    ui->statusbar->addWidget(ui->lblCollabName);

    connect(ui->btnLock, &QPushButton::clicked, this, &FMPrincipal::blockScreen);
    connect(ui->actionCollaborators, &QAction::triggered, this, &FMPrincipal::messageBoxTestButtons);
    connect(ui->btnNewSale, &QPushButton::clicked, this, &FMPrincipal::newSale);
    connect(ui->actionCollaborators, &QAction::triggered, this, &FMPrincipal::employeeManagement);
    connect(ui->actionStock, &QAction::triggered, this, &FMPrincipal::stockManagement);

    widgetList = ui->centralwidget->findChildren<QWidget*>();
    disableAllWidgets();
}

FMPrincipal::~FMPrincipal()
{
    delete ui;
}

void FMPrincipal::blockScreen()
{
    if(isUserLogged)
    {
        isUserLogged = false;
        ui->btnLock->setIcon(*icoClosedLock);
        disableAllWidgets();
    } else {
        FMLogin fmLogin;
        fmLogin.exec();
        ui->lblCollabName->setText(fmLogin.getCollabName());
        isUserLogged = fmLogin.getIsLogged();
        ui->btnLock->setIcon(*icoOpenedLock);

        QString userAccessLevel = fmLogin.getCollabAccessLevel();
        if(userAccessLevel == "USER_REGISTER_ONLY")
        {
            enableToRegisterOnly();
        } else if(userAccessLevel == "SELLER") {
            enableToSalespersonUser();
        } else if(userAccessLevel == "ADMINISTRATOR"){
            enableToAdministrator();
        }
    }
}

void FMPrincipal::enableAllWidgets()
{
    for(QWidget* widget : widgetList)
    {
        widget->setEnabled(true);
    }
    ui->menubar->setEnabled(true);
    ui->toolBar->setEnabled(true);
}

void FMPrincipal::disableAllWidgets()
{
    for(QWidget* widget : widgetList)
    {
        widget->setEnabled(false);
    }
    ui->menubar->setEnabled(false);
    ui->toolBar->setEnabled(false);
}

void FMPrincipal::enableToRegisterOnly()
{
    ui->menubar->setEnabled(true);
    ui->toolBar->setEnabled(true);

    ui->menuSistema->setEnabled(false);
    ui->actionStock->setEnabled(false);
    ui->actionSales->setEnabled(false);

    ui->actionCollaborators->setEnabled(true);
}

void FMPrincipal::enableToSalespersonUser()
{
    ui->menubar->setEnabled(true);
    ui->toolBar->setEnabled(true);

    ui->menuSistema->setEnabled(false);
    ui->actionCollaborators->setEnabled(false);

    ui->btnNewSale->setEnabled(true);
}

void FMPrincipal::enableToAdministrator()
{
    enableAllWidgets();
}

void FMPrincipal::messageBoxTestButtons()
{
    QMessageBox::warning(this, "OK", "Botão OK");
}

void FMPrincipal::newSale()
{
    FMNewSale fmNewSale;
    fmNewSale.exec();
}

void FMPrincipal::stockManagement()
{
    FMStockManagement fmStockMangement;
    fmStockMangement.exec();
}

void FMPrincipal::employeeManagement()
{
    FMEmployeeManagement fmEmployeeManagement;
    fmEmployeeManagement.exec();
}
