/********************************************************************************
** Form generated from reading ui file 'configplugin.ui'
**
** Created: Sun Nov 2 17:16:53 2008
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
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ConfigPlugin
{
public:
    QGridLayout *gridLayout;
    QListWidget *lw_effects;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ConfigPlugin)
    {
    if (ConfigPlugin->objectName().isEmpty())
        ConfigPlugin->setObjectName(QString::fromUtf8("ConfigPlugin"));
    ConfigPlugin->resize(477, 463);
    gridLayout = new QGridLayout(ConfigPlugin);
#ifndef Q_OS_MAC
    gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout->setMargin(9);
#endif
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    lw_effects = new QListWidget(ConfigPlugin);
    lw_effects->setObjectName(QString::fromUtf8("lw_effects"));
    lw_effects->setSelectionMode(QAbstractItemView::MultiSelection);
    lw_effects->setMovement(QListView::Static);
    lw_effects->setViewMode(QListView::IconMode);

    gridLayout->addWidget(lw_effects, 0, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
    hboxLayout->setSpacing(6);
#endif
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    okButton = new QPushButton(ConfigPlugin);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout->addWidget(okButton);

    cancelButton = new QPushButton(ConfigPlugin);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

    hboxLayout->addWidget(cancelButton);


    gridLayout->addLayout(hboxLayout, 1, 0, 1, 1);


    retranslateUi(ConfigPlugin);
    QObject::connect(okButton, SIGNAL(clicked()), ConfigPlugin, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), ConfigPlugin, SLOT(reject()));

    QMetaObject::connectSlotsByName(ConfigPlugin);
    } // setupUi

    void retranslateUi(QDialog *ConfigPlugin)
    {
    ConfigPlugin->setWindowTitle(QApplication::translate("ConfigPlugin", "Configurar Efectos", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("ConfigPlugin", "OK", 0, QApplication::UnicodeUTF8));
    cancelButton->setText(QApplication::translate("ConfigPlugin", "Cancel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(ConfigPlugin);
    } // retranslateUi

};

namespace Ui {
    class ConfigPlugin: public Ui_ConfigPlugin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGPLUGIN_H
