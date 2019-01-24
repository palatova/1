#include "nalichie.h"
#include "ui_nalichie.h"
#include "QtSql/QSqlQuery"
#include "QMessageBox"
nalichie::nalichie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nalichie)
{
    ui->setupUi(this);
     //фильтруем событие добавления айтемов
      ui->comboBox->addItem("1");
      ui->comboBox->addItem("2");
       ui->comboBox->addItem("3");
       ui->comboBox->addItem("4");

}
/*nalichie::nalichie(QWidget *parent) : QDialog(parent),
    ui(new Ui::nalichie){
  ui(new Ui::nalichie), m_doubleValidator(0, 0, 1, this)
{
  ui->setupUi(this);
  m_doubleValidator.setNotation(QDoubleValidator::StandardNotation);
  ui->size2->setValidator(&m_doubleValidator);
  connect(ui->size2, SIGNAL(textChanged(QString)), this, SLOT(on_changed()));

}
*/

nalichie::~nalichie()
{
    delete ui;
}

void nalichie::on_pushButton_clicked()
{
    //статус заказа
    //справочник для клиентов
    //справочник
    QString id1 = ui->id_costume_2->text();
    QString size1 = ui->comboBox->currentText();

    QSqlDatabase shop= QSqlDatabase::addDatabase("QSQLITE");
    shop.setDatabaseName("C:/sqlite/shop.db");
    shop.open();
    QSqlQuery query;
  // query.exec("SELECT nal FROM costumes where " "(id=1);");
  query.exec("SELECT nal FROM costumes where " "(id="+id1+") and (size="+ size1+");");
  //query.bindValue(":id1", id1);
     while (query.next())
     {
     QString nal = query.value(0).toString();
     ui->textEdit1->insertPlainText(nal+"\n");
     }

  qDebug()<<query.exec()<<endl;
}
