#include "costume.h"
#include "ui_costume.h"
#include "QtSql/QSqlQuery"
#include "QMessageBox"
Costume::Costume(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Costume)
{
    ui->setupUi(this);
}

Costume::~Costume()
{
    delete ui;
}

void Costume::on_pushButton_clicked()
{
    QString articul = ui->articul->text();
    QString size = ui->size->text();

QSqlDatabase shop= QSqlDatabase::addDatabase("QSQLITE");
   shop.setDatabaseName("C:/sqlite/shop.db");
   shop.open();
   QSqlQuery query;
   query.prepare("insert into costumes (id, size,nal) values(:articul,:size,1)");
   query.bindValue(":articul", articul);
   query.bindValue(":size", size);
   qDebug()<<query.exec()<<endl;
     }

void Costume::on_pushButton_2_clicked()
{
    QString articul = ui->articul->text();
    QString size = ui->size->text();

QSqlDatabase shop= QSqlDatabase::addDatabase("QSQLITE");
   shop.setDatabaseName("C:/sqlite/shop.db");
   shop.open();
   QSqlQuery query;
   query.prepare("if exists (select id from costumes where( (id=:articul) and(size=:size))) begin update costumes;"
                 " set nal = 1 where(id= articul)");
   query.bindValue(":articul", articul);
   query.bindValue(":size", size);
   qDebug()<<query.exec()<<endl;
}
