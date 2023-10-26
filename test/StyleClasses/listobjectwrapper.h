#ifndef LISTOBJECTWRAPPER_H
#define LISTOBJECTWRAPPER_H

#include <QWidget>
#include <QFile>

#include "ui_listobjectwrapper.h"
#include "stylesetter.h"

namespace Ui {
class ListObjectWrapper;
}

class ListObjectWrapper : public QWidget {
  Q_OBJECT

 public:
  explicit ListObjectWrapper(QWidget *parent = nullptr);
  ~ListObjectWrapper();

  void AddWidgetToLayout(QWidget *widget);

 private:
  Ui::ListObjectWrapper *ui;
};

#endif  // LISTOBJECTWRAPPER_H
