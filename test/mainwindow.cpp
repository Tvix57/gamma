#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->mainTabsLayout->setAlignment(Qt::AlignTop);
    ui->ItemsLayout->layout()->setAlignment(Qt::AlignTop);
    AddPanelInList(std::optional<QWidget*>(new DeviceInfo()));
    QFile file(":/Styles/styles/Style.css");
    file.open(QFile::ReadOnly|QFile::Text);
    setStyleSheet(file.readAll());
    file.close();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::AddPanelInList(std::optional<QWidget*> wgt) {
    if (wgt.has_value()) {
//        ui->ItemsLayout->addWidget(wgt.value());
        ui->ItemsLayout->layout()->addWidget(wgt.value());
    }
}


void MainWindow::on_pushButton_clicked() {
    AddPanelInList(std::optional<QWidget*>(new DeviceInfo()));
}

