#ifndef FMEMPLOYEEMANAGEMENT_H
#define FMEMPLOYEEMANAGEMENT_H

#include <QDialog>

namespace Ui {
class FMEmployeeManagement;
}

class FMEmployeeManagement : public QDialog
{
    Q_OBJECT

public:
    explicit FMEmployeeManagement(QWidget *parent = nullptr);
    ~FMEmployeeManagement();

private:
    Ui::FMEmployeeManagement *ui;
};

#endif // FMEMPLOYEEMANAGEMENT_H
