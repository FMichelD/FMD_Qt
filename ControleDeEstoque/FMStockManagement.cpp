#include "FMStockManagement.h"
#include "ui_FMStockManagement.h"

FMStockManagement::FMStockManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FMStockManagement)
{
    ui->setupUi(this);
}

FMStockManagement::~FMStockManagement()
{
    delete ui;
}
