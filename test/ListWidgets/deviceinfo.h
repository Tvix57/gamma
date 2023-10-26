#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QLabel>
#include <QMessageBox>
#include <QDir>

#include "IListObject.h"

namespace Ui {
class DeviceInfo;
}

enum class HeaderSize { Lowest, Low, Middle, High, Highest };

inline HeaderSize &operator++(HeaderSize &h) {
  if (h != HeaderSize::Highest) h = HeaderSize(static_cast<int>(h) + 1);
  return h;
}

inline HeaderSize &operator--(HeaderSize &h) {
  if (h != HeaderSize::Lowest) h = HeaderSize(static_cast<int>(h) - 1);
  return h;
}

inline QString HeaderSizeToString(HeaderSize s) {
  static QMap<HeaderSize, QString> m{{HeaderSize::Lowest, "h5"},
                                     {HeaderSize::Low, "h4"},
                                     {HeaderSize::Middle, "h3"},
                                     {HeaderSize::High, "h2"},
                                     {HeaderSize::Highest, "h1"}};
  return m[s];
}

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
  HeaderSize _headerSize = HeaderSize::Highest;
};

#endif  // DEVICEINFO_H
