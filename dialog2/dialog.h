#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
  Q_OBJECT
private:
  QLabel *label1, *label2;
  QLineEdit *lineEdit;
  QPushButton *button;

private slots:
  void showArea();

public:
  Dialog(QWidget *parent = 0);
  ~Dialog();
};

#endif // DIALOG_H
