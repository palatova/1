#ifndef COSTUME_H
#define COSTUME_H

#include <QDialog>
#include <QtSql>
#include<QtDebug>
#include<QFileInfo>
namespace Ui {
class Costume;
}

class Costume : public QDialog
{
    Q_OBJECT

public:
    explicit Costume(QWidget *parent = nullptr);
    ~Costume();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Costume *ui;
};

#endif // COSTUME_H
