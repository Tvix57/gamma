#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QWidget>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
#include <QFormLayout>

#include "IListObject.h"

namespace Ui {
class DeviceInfo;
}

enum HeaderSize{
    Higest = 0,
    High,
    Midle,
    Low,
    Lowest
};

class DeviceInfo : public QWidget, IListObject
{
    Q_OBJECT

public:
    explicit DeviceInfo(QWidget *parent = nullptr);
    ~DeviceInfo();
public slots:
    void GetData(QString json_way);

private:
    void show_data(const QJsonValue& json);
private slots:
    void on_detailBtn_clicked();

private:
    Ui::DeviceInfo *ui;
};

#endif // DEVICEINFO_H
