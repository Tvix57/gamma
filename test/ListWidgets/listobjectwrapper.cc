#include "listobjectwrapper.h"

#include <QFile>

#include "ui_listobjectwrapper.h"

ListObjectWrapper::ListObjectWrapper(QWidget *parent)
    : QWidget(parent), ui(new Ui::ListObjectWrapper) {
  ui->setupUi(this);
  ui->wrapper->setLayout(new QVBoxLayout());

  QFile file(":/Styles/styles/Style.css");
  file.open(QFile::ReadOnly | QFile::Text);
  setStyleSheet(file.readAll());
  file.close();
}

ListObjectWrapper::~ListObjectWrapper() { delete ui; }

void ListObjectWrapper::AddWidgetToLayout(QWidget *widget) {
  ui->wrapper->layout()->addWidget(widget);
  ui->wrapper->layout()->setAlignment(Qt::AlignmentFlag::AlignLeft);
}
