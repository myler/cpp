#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  Dialog w;
  w.setWindowFlags(Qt::Tool);
  w.show();

  return a.exec();
}