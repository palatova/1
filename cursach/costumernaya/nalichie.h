#ifndef NALICHIE_H
#define NALICHIE_H

#include <QDialog>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDoubleValidator>
namespace Ui {
class nalichie;
}

class nalichie : public QDialog
{
    Q_OBJECT

public:
    explicit nalichie(QWidget *parent = nullptr);
    ~nalichie();

private slots:
    void on_pushButton_clicked();

private:
    Ui::nalichie *ui;
     QDoubleValidator m_doubleValidator;
};

#endif // NALICHIE_H
