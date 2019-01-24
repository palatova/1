#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "nalichie.h"
#include "tablica_zakazov1.h"
#include "zakaz1.h"
#include "costume.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    zakaz1 window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
   nalichie window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    tablica_zakazov1 window;
    window.setModal(true);
    window.exec();



}



void MainWindow::on_pushButton_3_clicked()
{
    Costume window;
    window.setModal(true);
    window.exec();

}
