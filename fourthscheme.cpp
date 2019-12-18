#include "fourthscheme.h"
#include "ui_fourthscheme.h"
#include "functions.cpp"
#include <QDebug>

FourthScheme::FourthScheme(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FourthScheme)
{
    ui->setupUi(this);
    PD << 1 << 2 << 4 << 7 << 11;
    VE << 1 << 2 << 4 << 3 << 6 << 0 << 4 << 6 << 8 << 0 << 5;
}

FourthScheme::~FourthScheme()
{
    delete ui;
}

void FourthScheme::on_AddButton_clicked()
{
    int Row = ui->RowSpinBox->value();
    int Col = ui->ColumnSpinBox->value();
    int Value = ui->ValueSpinBox->value();
    while(Row > PD.size() || Col > PD.size())
    {
        if(PD.isEmpty())
        {
            PD.append(1);
        }
        else
        {
            PD.append(PD.at(PD.size() - 1) + 1);
        }
        VE.append(0);
    }

    AddElement(Row - 1, Col - 1, Value, &PD, &VE);
}

void FourthScheme::on_DelButton_clicked()
{
    int Row = ui->RowSpinBox->value();
    int Col = ui->ColumnSpinBox->value();
    DelElement(Row - 1, Col - 1, &PD, &VE);
}
