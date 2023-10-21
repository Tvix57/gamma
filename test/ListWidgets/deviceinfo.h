#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QWidget>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
#include <QTableView>


namespace Ui {
class DeviceInfo;
}

class DeviceInfo : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceInfo(QWidget *parent = nullptr);
    ~DeviceInfo();
public slots:
    void GetData(QString json_way);

private:
    void show_data(const QJsonValue& json, const QString& key);
private slots:
    void on_detailBtn_clicked();

private:
    Ui::DeviceInfo *ui;
    int _header_lvl = 0;
};

#endif // DEVICEINFO_H
