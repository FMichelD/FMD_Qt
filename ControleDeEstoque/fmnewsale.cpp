#include "FMNewSale.h"
#include "ui_FMNewSale.h"

FMNewSale::FMNewSale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FMNewSale)
{
    ui->setupUi(this);
}

FMNewSale::~FMNewSale()
{
    delete ui;
}
