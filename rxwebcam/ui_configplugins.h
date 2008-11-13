/********************************************************************************
** Form generated from reading ui file 'configplugins.ui'
**
** Created: Sun Nov 2 17:16:34 2008
**      by: Qt User Interface Compiler version 4.4.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONFIGPLUGINS_H
#define UI_CONFIGPLUGINS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ConfigPlugins
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout1;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout2;
    QTextEdit *te_infoPlugin;
    QSpacerItem *spacerItem;
    QPushButton *pb_close;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout3;
    QFrame *fr_actions;
    QGridLayout *gridLayout4;
    QPushButton *pb_configurePlugin;
    QCheckBox *cb_enablePlugin;
    QComboBox *lb_pluginList;
    QSpacerItem *spacerItem1;
    QGroupBox *groupBox;
    QLabel *tl_pluginPreview;

    void setupUi(QDialog *ConfigPlugins)
    {
    if (ConfigPlugins->objectName().isEmpty())
        ConfigPlugins->setObjectName(QString::fromUtf8("ConfigPlugins"));
    ConfigPlugins->resize(429, 519);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(ConfigPlugins->sizePolicy().hasHeightForWidth());
    ConfigPlugins->setSizePolicy(sizePolicy);
    ConfigPlugins->setMinimumSize(QSize(0, 0));
    gridLayout = new QGridLayout(ConfigPlugins);
#ifndef Q_OS_MAC
    gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout->setMargin(9);
#endif
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout1 = new QGridLayout();
#ifndef Q_OS_MAC
    gridLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout1->setMargin(0);
#endif
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    groupBox_3 = new QGroupBox(ConfigPlugins);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
    groupBox_3->setSizePolicy(sizePolicy1);
    groupBox_3->setMaximumSize(QSize(16777215, 210));
    gridLayout2 = new QGridLayout(groupBox_3);
#ifndef Q_OS_MAC
    gridLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout2->setMargin(9);
#endif
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    te_infoPlugin = new QTextEdit(groupBox_3);
    te_infoPlugin->setObjectName(QString::fromUtf8("te_infoPlugin"));
    sizePolicy1.setHeightForWidth(te_infoPlugin->sizePolicy().hasHeightForWidth());
    te_infoPlugin->setSizePolicy(sizePolicy1);
    te_infoPlugin->setMaximumSize(QSize(16777215, 200));
    te_infoPlugin->setLineWrapMode(QTextEdit::WidgetWidth);
    te_infoPlugin->setReadOnly(true);

    gridLayout2->addWidget(te_infoPlugin, 0, 0, 1, 1);


    gridLayout1->addWidget(groupBox_3, 0, 0, 1, 2);

    spacerItem = new QSpacerItem(356, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout1->addItem(spacerItem, 1, 0, 1, 1);

    pb_close = new QPushButton(ConfigPlugins);
    pb_close->setObjectName(QString::fromUtf8("pb_close"));

    gridLayout1->addWidget(pb_close, 1, 1, 1, 1);


    gridLayout->addLayout(gridLayout1, 1, 0, 1, 1);

    hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
    hboxLayout->setSpacing(6);
#endif
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    groupBox_2 = new QGroupBox(ConfigPlugins);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
    groupBox_2->setSizePolicy(sizePolicy2);
    gridLayout3 = new QGridLayout(groupBox_2);
#ifndef Q_OS_MAC
    gridLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout3->setMargin(9);
#endif
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    fr_actions = new QFrame(groupBox_2);
    fr_actions->setObjectName(QString::fromUtf8("fr_actions"));
    QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(fr_actions->sizePolicy().hasHeightForWidth());
    fr_actions->setSizePolicy(sizePolicy3);
    fr_actions->setFrameShape(QFrame::NoFrame);
    fr_actions->setFrameShadow(QFrame::Raised);
    gridLayout4 = new QGridLayout(fr_actions);
#ifndef Q_OS_MAC
    gridLayout4->setSpacing(6);
#endif
#ifndef Q_OS_MAC
    gridLayout4->setMargin(9);
#endif
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    pb_configurePlugin = new QPushButton(fr_actions);
    pb_configurePlugin->setObjectName(QString::fromUtf8("pb_configurePlugin"));

    gridLayout4->addWidget(pb_configurePlugin, 1, 0, 1, 1);

    cb_enablePlugin = new QCheckBox(fr_actions);
    cb_enablePlugin->setObjectName(QString::fromUtf8("cb_enablePlugin"));

    gridLayout4->addWidget(cb_enablePlugin, 0, 0, 1, 1);


    gridLayout3->addWidget(fr_actions, 1, 0, 1, 1);

    lb_pluginList = new QComboBox(groupBox_2);
    lb_pluginList->setObjectName(QString::fromUtf8("lb_pluginList"));
    QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(lb_pluginList->sizePolicy().hasHeightForWidth());
    lb_pluginList->setSizePolicy(sizePolicy4);

    gridLayout3->addWidget(lb_pluginList, 0, 0, 1, 1);


    hboxLayout->addWidget(groupBox_2);

    spacerItem1 = new QSpacerItem(21, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem1);

    groupBox = new QGroupBox(ConfigPlugins);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
    groupBox->setSizePolicy(sizePolicy1);
    tl_pluginPreview = new QLabel(groupBox);
    tl_pluginPreview->setObjectName(QString::fromUtf8("tl_pluginPreview"));
    tl_pluginPreview->setGeometry(QRect(11, 30, 186, 188));
    sizePolicy1.setHeightForWidth(tl_pluginPreview->sizePolicy().hasHeightForWidth());
    tl_pluginPreview->setSizePolicy(sizePolicy1);
    tl_pluginPreview->setScaledContents(true);

    hboxLayout->addWidget(groupBox);


    gridLayout->addLayout(hboxLayout, 0, 0, 1, 1);


    retranslateUi(ConfigPlugins);
    QObject::connect(pb_close, SIGNAL(clicked()), ConfigPlugins, SLOT(accept()));

    QMetaObject::connectSlotsByName(ConfigPlugins);
    } // setupUi

    void retranslateUi(QDialog *ConfigPlugins)
    {
    ConfigPlugins->setWindowTitle(QApplication::translate("ConfigPlugins", "Plugins", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("ConfigPlugins", "Informacion", 0, QApplication::UnicodeUTF8));
    pb_close->setText(QApplication::translate("ConfigPlugins", "Cerrar", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("ConfigPlugins", "Listado Complementos", 0, QApplication::UnicodeUTF8));
    pb_configurePlugin->setText(QApplication::translate("ConfigPlugins", "Configurar", 0, QApplication::UnicodeUTF8));
    cb_enablePlugin->setText(QApplication::translate("ConfigPlugins", "Habilitado", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("ConfigPlugins", "Preview", 0, QApplication::UnicodeUTF8));
    tl_pluginPreview->setText(QString());
    Q_UNUSED(ConfigPlugins);
    } // retranslateUi

};

namespace Ui {
    class ConfigPlugins: public Ui_ConfigPlugins {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGPLUGINS_H
