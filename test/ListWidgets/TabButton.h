#ifndef TABBUTTON_H
#define TABBUTTON_H

#include <QPushButton>
#include <QWidget>

class TabButton : public QPushButton {
  Q_OBJECT
 public:
  explicit TabButton(QWidget* parent = nullptr);
};

#endif  // TABBUTTON_H
