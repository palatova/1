#include "tablica_zakazov1.h"
#include "ui_tablica_zakazov1.h"
#include "QtSql/QSqlQuery"
#include "iomanip"
#include "QTableWidget"
//собрать с помощью cmake

tablica_zakazov1::tablica_zakazov1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tablica_zakazov1)
{
    ui->setupUi(this);
    QSqlDatabase shop= QSqlDatabase::addDatabase("QSQLITE");
    shop.setDatabaseName("C:/sqlite/shop.db");
    shop.open();
   //Осуществляем запрос
      QSqlQuery query;
      query.exec( "SELECT id,surname, name, name2, id_costume,size FROM tablica_zakazov");

      //Выводим значения из запроса
      ui->textEdit->insertPlainText("№ Фамилия:  Имя:    Отчество:    костюм: размер: \n" );
      while (query.next())
      {
      QString id = query.value(0).toString();
      QString surname = query.value(1).toString();
      QString name = query.value(2).toString();
      QString name2 = query.value(3).toString();
      QString id_costume = query.value(4).toString();
      QString size = query.value(5).toString();


 ui->textEdit->insertPlainText(id+ " " +surname+" "+name+" "+name2+" "+id_costume+ " "+size+"\n");
      }
      /*
  ui->tableWidget->setColumnCount(6);
 ui->tableWidget->setRowCount(12); //Количество строк
 for
 QTableWidgetItem *itm= new QTableWidgetItem(tr("%n").arg(surname));
  ui->tableWidget->setItem(1,2,itm);

//setw(12)
*/
}


tablica_zakazov1::~tablica_zakazov1()
{
    delete ui;
}




