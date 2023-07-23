#ifndef FMSTOCKMANAGEMENT_H
#define FMSTOCKMANAGEMENT_H

#include <QDialog>

namespace Ui {
class FMStockManagement;
}

class FMStockManagement : public QDialog
{
    Q_OBJECT

public:
    explicit FMStockManagement(QWidget *parent = nullptr);
    ~FMStockManagement();

private:
    Ui::FMStockManagement *ui;
};

#endif // FMSTOCKMANAGEMENT_H
