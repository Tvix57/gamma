#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
#include <QFormLayout>
#include <QLabel>

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

class DeviceInfo : public IListObject
{

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
    HeaderSize _headerSize = HeaderSize::Higest;
};

#endif // DEVICEINFO_H
