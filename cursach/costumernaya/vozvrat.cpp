#include "vozvrat.h"
#include "ui_vozvrat.h"

vozvrat::vozvrat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vozvrat)
{
    ui->setupUi(this);
}

vozvrat::~vozvrat()
{
    delete ui;
}
