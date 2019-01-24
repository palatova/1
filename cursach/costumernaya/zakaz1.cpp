#include "zakaz1.h"
#include "ui_zakaz1.h"
#include "QMessageBox"
#include "QToolTip"
#include "QtSql/QSqlQuery"
#include <QAbstractListModel>
zakaz1::zakaz1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zakaz1)
{
    ui->setupUi(this);
     //ui->comboBox->installEventFilter(this);
     //фильтруем событие добавления айтемов
    //  ui->comboBox->addItem("Tatyana");
     //  ui->comboBox->addItem("Inga");
     //  ui->comboBox->addItem("Katya");

}
//zakaz1::zakaz1(QWidget *parent) : QDialog(parent),
   // ui(new Ui::zakaz1){
  /*ui(new Ui::zakaz1), m_doubleValidator(-100, 1000, 2, this)
{
  ui->setupUi(this);
  m_doubleValidator.setNotation(QDoubleValidator::StandardNotation);
  ui->fio->setValidator(&m_doubleValidator);
  connect(ui->fio, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));
      */
//}


zakaz1::~zakaz1()
{
    delete ui;
}

void zakaz1::on_pushButton_clicked()
{
    QString surname = ui->surname->text();
      QString name = ui->name->text();
    //QString name = ui->comboBox->currentText();
    QString name2 = ui->name2->text();
    QString id_costume = ui->id_costume->text();
    QString size = ui->size->text();


   QSqlDatabase shop= QSqlDatabase::addDatabase("QSQLITE");
   shop.setDatabaseName("C:/sqlite/shop.db");
   shop.open();
   QSqlQuery query;
   query.prepare("declare @name varchar(100)),"
                 "@name2 varchar(100);"
                 "if exists (select id from client where(surname = :surname) begin ( set @name=123;");
   query.bindValue(":surname", surname);
   query.bindValue("@name", name);
   query.prepare("insert into tablica_zakazov (surname,name, name2,id_costume, size) values(:surname,:name,:name2,:id_costume,:size)");
   query.bindValue(":surname", surname);

   query.bindValue(":name", name);
   query.bindValue(":name2", name2);
   query.bindValue(":id_costume",id_costume);
   query.bindValue(":size", size);
   qDebug()<<query.exec()<<endl;
   QSqlQuery query2;
   query2.prepare("insert into clients (surname,name, name2) values(:surname,:name,:name2)");
   query2.bindValue(":surname", surname);
   query2.bindValue(":name", name);
   query2.bindValue(":name2", name2);
   qDebug()<<query2.exec()<<endl;
}






void zakaz1::on_surname_textChanged()
{
    QToolTip::showText(this->mapToGlobal(QPoint(0, 40)), tr("Если клиент делает не первый заказ, поставьте индекс рядом с его фамилией = номеру заказа"));
}
