/********************************************************************************
** Form generated from reading ui file 'opendevice.ui'
**
** Created: Sun Nov 2 17:16:34 2008
**      by: Qt User Interface Compiler version 4.4.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPENDEVICE_H
#define UI_OPENDEVICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenDevice
{
public:
    QListWidget *lw_devices;
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *OpenDevice)
    {
    if (OpenDevice->objectName().isEmpty())
        OpenDevice->setObjectName(QString::fromUtf8("OpenDevice"));
    OpenDevice->resize(400, 300);
    lw_devices = new QListWidget(OpenDevice);
    lw_devices->setObjectName(QString::fromUtf8("lw_devices"));
    lw_devices->setGeometry(QRect(20, 20, 361, 221));
    lw_devices->setViewMode(QListView::IconMode);
    layoutWidget = new QWidget(OpenDevice);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(30, 260, 351, 33));
    hboxLayout = new QHBoxLayout(layoutWidget);
#ifndef Q_OS_MAC
    hboxLayout->setSpacing(6);
#endif
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    hboxLayout->setContentsMargins(0, 0, 0, 0);
    spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    okButton = new QPushButton(layoutWidget);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout->addWidget(okButton);

    cancelButton = new QPushButton(layoutWidget);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

    hboxLayout->addWidget(cancelButton);


    retranslateUi(OpenDevice);
    QObject::connect(okButton, SIGNAL(clicked()), OpenDevice, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), OpenDevice, SLOT(reject()));

    QMetaObject::connectSlotsByName(OpenDevice);
    } // setupUi

    void retranslateUi(QDialog *OpenDevice)
    {
    OpenDevice->setWindowTitle(QApplication::translate("OpenDevice", "Dispositivos Detectados", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("OpenDevice", "OK", 0, QApplication::UnicodeUTF8));
    cancelButton->setText(QApplication::translate("OpenDevice", "Cancel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(OpenDevice);
    } // retranslateUi

};

namespace Ui {
    class OpenDevice: public Ui_OpenDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENDEVICE_H
