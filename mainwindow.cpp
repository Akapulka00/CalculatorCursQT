#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   result=0;
   operation=0;
   ui->setupUi(this);
   buttons.append(ui->pushButton);
   buttons.append(ui->pushButton_2);
   buttons.append(ui->pushButton_3);
   buttons.append(ui->pushButton_4);
   buttons.append(ui->pushButton_5);
   buttons.append(ui->pushButton_6);
   buttons.append(ui->pushButton_7);
   buttons.append(ui->pushButton_8);
   buttons.append(ui->pushButton_9);
   buttons.append(ui->pushButton_10);
   buttons.append(ui->pushButton_11);


   for(qint32 i=0;i<10;i++){
      connect(buttons[i], &QPushButton::clicked, this, [=] () { number_pushButtonclicked(i); });
   }
}

MainWindow::~MainWindow()
{
   delete ui;
}
void MainWindow::number_pushButtonclicked(qint32 i){
   //тут описание клика числовой кнопки
   QString z=ui->lineEdit->text();
   if(z.trimmed().isEmpty() && i==0){
   }else{
      if(z=="0"){
      ui->lineEdit->setText("");
      }else{
   z.append(QString::number(i));
         ui->lineEdit->setText(z);}
   }
}



void MainWindow::on_pushButton_14_clicked()//+
{
   if(operation!=1 && operation!=0){
   preCount();
   }else{
   bool ok;
     a=ui->lineEdit->text().toInt(&ok,10);
   result+=a;
     ui->lineEdit->setText("");}
   operation=1;
}
void MainWindow::preCount(){
   bool ok;
   a=ui->lineEdit->text().toInt(&ok,10);
   switch(operation){
   case 1:
   result=result+a;
   ui->lineEdit->setText("");
   break;
   case 2:
   result=result+a;
   ui->lineEdit->setText("");
   break;
   }
}

void MainWindow::on_pushButton_15_clicked()// ->
{
   bool ok;
    a=ui->lineEdit->text().toInt(&ok,10);
   switch(operation){
       case 1:
    result=result+a;
   ui->lineEdit->setText(QString::number(result));
    result=0;
   break;
       case 2:
   result=result-a;
    ui->lineEdit->setText(QString::number(result));
    result=0;
    break;
       case 3:
    result=result*a;
    ui->lineEdit->setText(QString::number(result));
    result=0;
    break;
       case 4:
    result=result/a;
    ui->lineEdit->setText(QString::number(result));
    result=0;
    break;
       case 5:
    result=result%a;
    ui->lineEdit->setText(QString::number(result));
    result=0;
    break;
       }
       operation=0;
}


void MainWindow::on_pushButton_13_clicked()//-
{

       if(operation!=2 && operation!=0){
    preCount();
       }else{
       bool ok;
       qint32 a=ui->lineEdit->text().toInt(&ok,10);
       result=a-result;
       ui->lineEdit->setText("");}
        operation=2;
}


void MainWindow::on_pushButton_18_clicked()// del
{
        operation=0;
        a=0;
        result=0;
         ui->lineEdit->setText("");
}


void MainWindow::on_pushButton_17_clicked()// c
{
         QString z=ui->lineEdit->text();
         if(z.trimmed().isEmpty()!=1 ){
         z.resize(z.size() - 1);
         ui->lineEdit->setText(z);
         }
}


void MainWindow::on_pushButton_12_clicked()//*
{
         if(result==0)
         result=1;
         if(operation!=3 && operation!=0){
         preCount();
         }else{
         bool ok;
         qint32 a=ui->lineEdit->text().toInt(&ok,10);
         result=result*a;
         ui->lineEdit->setText("");}
         operation=3;

}


void MainWindow::on_pushButton_11_clicked()// /
{
         if(result==0)
         result=1;
         if(operation!=4 && operation!=0){
         preCount();
         }else{
         bool ok;
         qint32 a=ui->lineEdit->text().toInt(&ok,10);
         result=a/result;
         ui->lineEdit->setText("");}
         operation=4;

}


void MainWindow::on_pushButton_16_clicked()//%
{
         if(operation!=5 && operation!=0){
         preCount();
         }else{
         bool ok;
         qint32 a=ui->lineEdit->text().toInt(&ok,10);
         if(result==0){
         result=a;
         }else
         result=a%result;
         ui->lineEdit->setText("");}
         operation=5;
}

