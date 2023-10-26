#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "listobjectwrapper.h"
#include "stylesetter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->mainTabsLayout->setAlignment(Qt::AlignTop);
  ui->ItemsLayout->layout()->setAlignment(Qt::AlignTop);
  AddPanelInList(std::optional<QWidget *>(new DeviceInfo()));
  StyleSetter::setStyle(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::AddPanelInList(std::optional<QWidget *> wgt) {
  if (wgt.has_value()) {
    ListObjectWrapper *wrapper = new ListObjectWrapper;
    wrapper->AddWidgetToLayout(wgt.value());
    ui->ItemsLayout->layout()->addWidget(wrapper);
  }
}

void MainWindow::on_pushButton_clicked() {
  AddPanelInList(std::optional<QWidget *>(new DeviceInfo()));
}
