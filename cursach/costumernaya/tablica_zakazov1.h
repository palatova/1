#ifndef TABLICA_ZAKAZOV1_H
#define TABLICA_ZAKAZOV1_H

#include <QDialog>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>
namespace Ui {
class tablica_zakazov1;
}

class tablica_zakazov1 : public QDialog
{
    Q_OBJECT

public:
    explicit tablica_zakazov1(QWidget *parent = nullptr);
    ~tablica_zakazov1();

private slots:


private:
    Ui::tablica_zakazov1 *ui;
};

#endif // TABLICA_ZAKAZOV1_H
