#include "listobjectwrapper.h"


ListObjectWrapper::ListObjectWrapper(QWidget *parent)
    : QWidget(parent), ui(new Ui::ListObjectWrapper) {
  ui->setupUi(this);
  ui->wrapper->setLayout(new QVBoxLayout());
  StyleSetter::setStyle(this);
}

ListObjectWrapper::~ListObjectWrapper() { delete ui; }

void ListObjectWrapper::AddWidgetToLayout(QWidget *widget) {
  ui->wrapper->layout()->addWidget(widget);
  ui->wrapper->layout()->setAlignment(Qt::AlignmentFlag::AlignLeft);
}
