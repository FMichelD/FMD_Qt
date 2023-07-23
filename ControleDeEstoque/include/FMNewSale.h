#ifndef FMNEWSALE_H
#define FMNEWSALE_H

#include <QDialog>

namespace Ui {
class FMNewSale;
}

class FMNewSale : public QDialog
{
    Q_OBJECT

public:
    explicit FMNewSale(QWidget *parent = nullptr);
    ~FMNewSale();

private:
    Ui::FMNewSale *ui;
};

#endif // FMNEWSALE_H
