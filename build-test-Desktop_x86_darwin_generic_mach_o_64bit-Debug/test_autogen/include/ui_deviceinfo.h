/********************************************************************************
** Form generated from reading UI file 'deviceinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICEINFO_H
#define UI_DEVICEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeviceInfo
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *dataLayout;
    QPushButton *detailBtn;

    void setupUi(QWidget *DeviceInfo)
    {
        if (DeviceInfo->objectName().isEmpty())
            DeviceInfo->setObjectName(QString::fromUtf8("DeviceInfo"));
        DeviceInfo->resize(415, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DeviceInfo->sizePolicy().hasHeightForWidth());
        DeviceInfo->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DeviceInfo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dataLayout = new QVBoxLayout();
        dataLayout->setObjectName(QString::fromUtf8("dataLayout"));

        verticalLayout->addLayout(dataLayout);

        detailBtn = new QPushButton(DeviceInfo);
        detailBtn->setObjectName(QString::fromUtf8("detailBtn"));

        verticalLayout->addWidget(detailBtn);


        retranslateUi(DeviceInfo);

        QMetaObject::connectSlotsByName(DeviceInfo);
    } // setupUi

    void retranslateUi(QWidget *DeviceInfo)
    {
        DeviceInfo->setWindowTitle(QCoreApplication::translate("DeviceInfo", "Form", nullptr));
        detailBtn->setText(QCoreApplication::translate("DeviceInfo", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceInfo: public Ui_DeviceInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICEINFO_H
