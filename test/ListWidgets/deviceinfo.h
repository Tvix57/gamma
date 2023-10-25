#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QFile>
#include <QFormLayout>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QLabel>
#include <QMessageBox>

#include "IListObject.h"

namespace Ui {
class DeviceInfo;
}

enum HeaderSize { Higest = 0, High, Midle, Low, Lowest };

class DeviceInfo : public IListObject {
  Q_OBJECT

 public:
  explicit DeviceInfo(QWidget *parent = nullptr);
  ~DeviceInfo();
 public slots:
  void GetData(QString json_way);

 private:
  void show_data(const QJsonValue &json);
 private slots:
  void on_detailBtn_clicked();

 private:
  Ui::DeviceInfo *ui;
  HeaderSize _headerSize = HeaderSize::Higest;
};

#endif  // DEVICEINFO_H
