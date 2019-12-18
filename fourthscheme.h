#ifndef FOURTHSCHEME_H
#define FOURTHSCHEME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FourthScheme; }
QT_END_NAMESPACE

class FourthScheme : public QMainWindow
{
    Q_OBJECT

public:
    FourthScheme(QWidget *parent = nullptr);
    ~FourthScheme();

private slots:
    void on_AddButton_clicked();

    void on_DelButton_clicked();

private:
    Ui::FourthScheme *ui;
    QVector <int> PD;
    QVector <int> VE;
};
#endif // FOURTHSCHEME_H
