/********************************************************************************
** Form generated from reading ui file 'configplugin.ui'
**
** Created: Sun Nov 2 17:17:02 2008
**      by: Qt User Interface Compiler version 4.4.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONFIGPLUGIN_H
#define UI_CONFIGPLUGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ConfigPlugin
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *le_ip;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cb_allips;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QSpinBox *sb_port;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QSpinBox *sb_seconds;
    QLabel *label_5;
    QLabel *label_11;
    QLabel *tl_currentip;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ConfigPlugin)
    {
    if (ConfigPlugin->objectName().isEmpty())
        ConfigPlugin->setObjectName(QString::fromUtf8("ConfigPlugin"));
    ConfigPlugin->resize(435, 334);
    gridLayout_5 = new QGridLayout(ConfigPlugin);
    gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
    groupBox = new QGroupBox(ConfigPlugin);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout_4 = new QGridLayout(groupBox);
    gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
    gridLayout = new QGridLayout();
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    le_ip = new QLineEdit(groupBox);
    le_ip->setObjectName(QString::fromUtf8("le_ip"));

    gridLayout->addWidget(le_ip, 0, 1, 1, 1);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

    cb_allips = new QCheckBox(groupBox);
    cb_allips->setObjectName(QString::fromUtf8("cb_allips"));

    gridLayout->addWidget(cb_allips, 1, 1, 1, 1);


    gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

    gridLayout_2 = new QGridLayout();
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

    sb_port = new QSpinBox(groupBox);
    sb_port->setObjectName(QString::fromUtf8("sb_port"));
    sb_port->setMinimum(1);
    sb_port->setMaximum(65534);
    sb_port->setValue(6050);

    gridLayout_2->addWidget(sb_port, 0, 1, 1, 1);

    horizontalSpacer_3 = new QSpacerItem(130, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setScaledContents(false);
    label_3->setWordWrap(true);

    gridLayout_2->addWidget(label_3, 1, 1, 1, 1);


    gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 1);

    gridLayout_3 = new QGridLayout();
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

    sb_seconds = new QSpinBox(groupBox);
    sb_seconds->setObjectName(QString::fromUtf8("sb_seconds"));
    sb_seconds->setMinimum(1);
    sb_seconds->setMaximum(3600);

    gridLayout_3->addWidget(sb_seconds, 0, 1, 1, 1);

    label_5 = new QLabel(groupBox);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    gridLayout_3->addWidget(label_5, 0, 2, 1, 1);


    gridLayout_4->addLayout(gridLayout_3, 2, 0, 1, 1);


    gridLayout_5->addWidget(groupBox, 0, 0, 1, 3);

    label_11 = new QLabel(ConfigPlugin);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setWordWrap(true);

    gridLayout_5->addWidget(label_11, 1, 0, 1, 3);

    tl_currentip = new QLabel(ConfigPlugin);
    tl_currentip->setObjectName(QString::fromUtf8("tl_currentip"));

    gridLayout_5->addWidget(tl_currentip, 2, 0, 1, 3);

    horizontalSpacer_4 = new QSpacerItem(206, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout_5->addItem(horizontalSpacer_4, 3, 0, 1, 1);

    pushButton = new QPushButton(ConfigPlugin);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    gridLayout_5->addWidget(pushButton, 3, 1, 1, 1);

    pushButton_2 = new QPushButton(ConfigPlugin);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

    gridLayout_5->addWidget(pushButton_2, 3, 2, 1, 1);

    QWidget::setTabOrder(le_ip, cb_allips);
    QWidget::setTabOrder(cb_allips, sb_port);
    QWidget::setTabOrder(sb_port, sb_seconds);
    QWidget::setTabOrder(sb_seconds, pushButton);
    QWidget::setTabOrder(pushButton, pushButton_2);

    retranslateUi(ConfigPlugin);
    QObject::connect(pushButton, SIGNAL(clicked()), ConfigPlugin, SLOT(accept()));
    QObject::connect(pushButton_2, SIGNAL(clicked()), ConfigPlugin, SLOT(reject()));

    QMetaObject::connectSlotsByName(ConfigPlugin);
    } // setupUi

    void retranslateUi(QDialog *ConfigPlugin)
    {
    ConfigPlugin->setWindowTitle(QApplication::translate("ConfigPlugin", "Configurar Efectos", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("ConfigPlugin", "Server Info", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("ConfigPlugin", "Direccion IP:", 0, QApplication::UnicodeUTF8));
    cb_allips->setText(QApplication::translate("ConfigPlugin", "Escuchar en todas las interfaces", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("ConfigPlugin", "Puerto:", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("ConfigPlugin", "Solo el administrador puede seleccionar entre 1 y 1024", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("ConfigPlugin", "Actualizar Imagen cada:", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("ConfigPlugin", "segundos", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("ConfigPlugin", "Este plugin de ejemplo, puede mejorarse agregando whitelists de acceso, keep-alive, data save, etc.", 0, QApplication::UnicodeUTF8));
    tl_currentip->setText(QApplication::translate("ConfigPlugin", "---", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("ConfigPlugin", "Aceptar", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("ConfigPlugin", "Cancelar", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(ConfigPlugin);
    } // retranslateUi

};

namespace Ui {
    class ConfigPlugin: public Ui_ConfigPlugin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGPLUGIN_H
