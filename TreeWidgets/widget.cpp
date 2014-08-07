#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);
  init();
  connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int))
          , this, SLOT(treeItemChanged(QTreeWidgetItem*,int));
}

Widget::~Widget()
{
  delete ui;
}
