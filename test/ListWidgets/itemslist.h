#ifndef ITEMSLIST_H
#define ITEMSLIST_H

#include <QScrollArea>
#include <QWidget>

class ItemsList : public QScrollArea {
  Q_OBJECT
 public:
  explicit ItemsList(QWidget* parent = nullptr);
};

#endif  // ITEMSLIST_H
