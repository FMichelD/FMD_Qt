#include "FMEmployeeManagement.h"
#include "ui_FMEmployeeManagement.h"

FMEmployeeManagement::FMEmployeeManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FMEmployeeManagement)
{
    ui->setupUi(this);
}

FMEmployeeManagement::~FMEmployeeManagement()
{
    delete ui;
}
