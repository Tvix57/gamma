#include "deviceinfo.h"

#include "ui_deviceinfo.h"

DeviceInfo::DeviceInfo(QWidget *parent)
    : IListObject(parent), ui(new Ui::DeviceInfo) {
  ui->setupUi(this);
  GetData(":/Data/data/data.json");

  QFile css(":/Styles/styles/Style.css");
  css.open(QFile::ReadOnly | QFile::Text);
  setStyleSheet(css.readAll());
  css.close();
}

DeviceInfo::~DeviceInfo() { delete ui; }

void DeviceInfo::GetData(QString json_way) {
  QFile file(json_way);
  if (!file.open(QIODevice::ReadOnly)) {
    qWarning() << "Не удалось открыть файл:" << file.errorString();
    return;
  }
  QByteArray fileData = file.readAll();
  file.close();
  QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
  if (jsonDocument.isNull()) {
    qWarning() << "Недействительные JSON данные";
    return;
  }
  show_data(jsonDocument.object());
}

void DeviceInfo::show_data(const QJsonValue &json) {
  if (json.isObject()) {
    QJsonObject object = json.toObject();
    for (auto it = object.begin(); it != object.end();) {
      if (it.value().isObject()) {
        QLabel *title = new QLabel(it.key(), this);
        title->setWhatsThis(HeaderSizeToString(_headerSize));
        --_headerSize;
        title->setWordWrap(true);
        ui->dataLayout->addWidget(title);
        show_data(it.value());
      } else {
        QWidget *tab = new QWidget(this);
        QGridLayout *lay = new QGridLayout(tab);
        lay->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        tab->setLayout(lay);
        for (; it != object.end(); ++it) {
          QLabel *key = new QLabel(it.key(), this);
          key->setAlignment(Qt::AlignTop);
          key->setWhatsThis(HeaderSizeToString(_headerSize));

          QLabel *value = new QLabel(it.value().toString(), this);
          value->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
          value->setWordWrap(true);
          value->setWhatsThis(HeaderSizeToString(_headerSize));

          lay->addWidget(key, lay->rowCount(), 0);
          lay->addWidget(value, lay->rowCount() - 1, 1);
        }
        ui->dataLayout->addWidget(tab);
      }
      if (it != object.end()) ++it;
    }
  } else if (json.isArray()) {
    QJsonArray array = json.toArray();
    for (const QJsonValue &val : array) {
      show_data(val);
    }
  }
  ++_headerSize;
}

void DeviceInfo::on_detailBtn_clicked() {
  QMessageBox msg(this);
  //  msg.setWindowFlags(Qt::Window | Qt::FramelessWindowHint |
  //                     Qt::WindowCloseButtonHint);
  msg.setWindowTitle("Детали по устройству");
  msg.setText(
      "Какое то описание прошивки может быть длинным в несколько строчек "
      "текста расположенном тут");
  msg.exec();
}
