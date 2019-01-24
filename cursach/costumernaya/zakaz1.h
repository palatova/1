#ifndef ZAKAZ1_H
#define ZAKAZ1_H

#include <QDialog>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDoubleValidator>
namespace Ui {
class zakaz1;
}

class zakaz1 : public QDialog
{
    Q_OBJECT

public:
    explicit zakaz1(QWidget *parent = nullptr);
    ~zakaz1();



private slots:


    void on_pushButton_clicked();


    //void on_fio_textChanged();


    void on_surname_textChanged();

private:
    Ui::zakaz1 *ui;
     QDoubleValidator m_doubleValidator;
};

#endif // ZAKAZ1_H
