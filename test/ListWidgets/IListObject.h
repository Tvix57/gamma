#ifndef ILISTOBJECT_H
#define ILISTOBJECT_H

#include <QWidget>

class IListObject : public QWidget {
    Q_OBJECT
 public:
    explicit IListObject(QWidget * parent = nullptr) :QWidget(parent) {}
};

#endif // ILISTOBJECT_H
