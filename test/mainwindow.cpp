#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainTabsLayout->setAlignment(Qt::AlignTop);
    ui->ItemsLayout->setAlignment(Qt::AlignTop);
    AddPanelInList(std::optional<QWidget*>(new DeviceInfo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddPanelInList(std::optional<QWidget*> wgt)
{
    if (wgt.has_value()) {
        ui->ItemsLayout->addWidget(wgt.value());
    }
}


void MainWindow::on_pushButton_clicked()
{
    AddPanelInList(std::optional<QWidget*>(new DeviceInfo()));
}

