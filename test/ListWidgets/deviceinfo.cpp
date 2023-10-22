#include "deviceinfo.h"
#include "QtWidgets/qlabel.h"
#include "ui_deviceinfo.h"

DeviceInfo::DeviceInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceInfo) {
    ui->setupUi(this);
    GetData(":/Data/data/data.json");
}

DeviceInfo::~DeviceInfo() {
    delete ui;
}

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

void DeviceInfo::show_data(const QJsonValue& json) {
    if (json.isObject()) {
        QJsonObject object = json.toObject();
        for (auto it = object.begin(); it != object.end();) {
            if (it.value().isObject()) {
                ui->dataLayout->addWidget(new QLabel(it.key(), this));
                show_data(it.value());
            } else {
                QWidget *tab = new QWidget(this);
                QFormLayout *lay = new QFormLayout(tab);
                tab->setLayout(lay);
                for(; it != object.end(); ++it) {

                    lay->addRow(it.key(), new QLabel(it.value().toString()));
                }
                ui->dataLayout->addWidget(tab);
            }
            if (it != object.end()) ++it;
        }
    } else if (json.isArray()) {
        QJsonArray array = json.toArray();
        for (const QJsonValue& val : array) {
            show_data(val);
        }
    }
}

void DeviceInfo::on_detailBtn_clicked() {
    QMessageBox msg(this);
    msg.setWindowTitle("Детали по устройству");
    msg.setText("Какое то описание прошивки может быть длинным в несколько строчек текста расположенном тут");
    msg.exec();
}

