#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
   Q_OBJECT

   public:
   MainWindow(QWidget *parent = nullptr);
   ~MainWindow();
   void preCount();
   signals:
      void valueChanged(int newValue);


   private slots:
       void number_pushButtonclicked(qint32);



       void on_pushButton_14_clicked();

       void on_pushButton_15_clicked();

       void on_pushButton_13_clicked();

       void on_pushButton_18_clicked();

       void on_pushButton_17_clicked();

       void on_pushButton_12_clicked();

       void on_pushButton_11_clicked();

       void on_pushButton_16_clicked();

   private:
   QVector<QPushButton*> buttons;
   Ui::MainWindow *ui;
   qint32 result;
   qint8 operation;
   qint32 a;
};
#endif // MAINWINDOW_H
