#include "itemslist.h"

#include <QLayout>
ItemsList::ItemsList(QWidget* parent) : QScrollArea(parent) {
  QWidget* wgt = new QWidget();
  wgt->setLayout(new QVBoxLayout());
  setWidget(wgt);
}
