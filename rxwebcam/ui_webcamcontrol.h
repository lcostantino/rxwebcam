/********************************************************************************
** Form generated from reading ui file 'webcamcontrol.ui'
**
** Created: Sun Nov 2 17:16:34 2008
**      by: Qt User Interface Compiler version 4.4.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WEBCAMCONTROL_H
#define UI_WEBCAMCONTROL_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_WebcamControl
{
public:
    QGridLayout *gridLayout;
    QLabel *textLabel1;
    QGroupBox *bg_common;
    QGridLayout *gridLayout_3;
    QGridLayout *bg_commonLayout;
    QSpacerItem *spacer1;
    QPushButton *pushButton1;

    void setupUi(QDialog *WebcamControl)
    {
    if (WebcamControl->objectName().isEmpty())
        WebcamControl->setObjectName(QString::fromUtf8("WebcamControl"));
    WebcamControl->resize(448, 265);
    QPalette palette;
    QBrush brush(QColor(0, 0, 0, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(246, 246, 246, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush1);
    QBrush brush2(QColor(255, 255, 255, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Light, brush2);
    QBrush brush3(QColor(250, 250, 250, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
    QBrush brush4(QColor(123, 123, 123, 255));
    brush4.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
    QBrush brush5(QColor(164, 164, 164, 255));
    brush5.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
    QBrush brush6(QColor(255, 0, 0, 255));
    brush6.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Text, brush6);
    palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
    palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Active, QPalette::Base, brush2);
    palette.setBrush(QPalette::Active, QPalette::Window, brush2);
    palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
    QBrush brush7(QColor(255, 221, 118, 255));
    brush7.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Highlight, brush7);
    QBrush brush8(QColor(3, 3, 3, 255));
    brush8.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush8);
    QBrush brush9(QColor(0, 0, 192, 255));
    brush9.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Link, brush9);
    QBrush brush10(QColor(128, 0, 128, 255));
    brush10.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush10);
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
    palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush6);
    palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
    palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush8);
    palette.setBrush(QPalette::Inactive, QPalette::Link, brush9);
    palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush10);
    QBrush brush11(QColor(128, 128, 128, 255));
    brush11.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush11);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush6);
    palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush11);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
    palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
    palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush8);
    palette.setBrush(QPalette::Disabled, QPalette::Link, brush9);
    palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush10);
    WebcamControl->setPalette(palette);
    gridLayout = new QGridLayout(WebcamControl);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    textLabel1 = new QLabel(WebcamControl);
    textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(textLabel1->sizePolicy().hasHeightForWidth());
    textLabel1->setSizePolicy(sizePolicy);
    textLabel1->setTextFormat(Qt::PlainText);
    textLabel1->setScaledContents(true);
    textLabel1->setWordWrap(true);

    gridLayout->addWidget(textLabel1, 0, 0, 1, 2);

    bg_common = new QGroupBox(WebcamControl);
    bg_common->setObjectName(QString::fromUtf8("bg_common"));
    bg_common->setAutoFillBackground(false);
    gridLayout_3 = new QGridLayout(bg_common);
    gridLayout_3->setSpacing(6);
    gridLayout_3->setMargin(11);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    bg_commonLayout = new QGridLayout();
    bg_commonLayout->setSpacing(6);
    bg_commonLayout->setObjectName(QString::fromUtf8("bg_commonLayout"));
    bg_commonLayout->setHorizontalSpacing(3);

    gridLayout_3->addLayout(bg_commonLayout, 0, 0, 1, 1);


    gridLayout->addWidget(bg_common, 1, 0, 1, 2);

    spacer1 = new QSpacerItem(321, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(spacer1, 2, 0, 1, 1);

    pushButton1 = new QPushButton(WebcamControl);
    pushButton1->setObjectName(QString::fromUtf8("pushButton1"));

    gridLayout->addWidget(pushButton1, 2, 1, 1, 1);


    retranslateUi(WebcamControl);
    QObject::connect(pushButton1, SIGNAL(clicked()), WebcamControl, SLOT(close()));

    QMetaObject::connectSlotsByName(WebcamControl);
    } // setupUi

    void retranslateUi(QDialog *WebcamControl)
    {
    WebcamControl->setWindowTitle(QApplication::translate("WebcamControl", "Webcam Control ", 0, QApplication::UnicodeUTF8));
    textLabel1->setText(QApplication::translate("WebcamControl", "Cuidado: algunos controladores internos pueden ser usados para test, el uso de los los mismos puede provocar el mal funcionamiento de la aplicacion", 0, QApplication::UnicodeUTF8));
    bg_common->setTitle(QApplication::translate("WebcamControl", "Controls", 0, QApplication::UnicodeUTF8));
    pushButton1->setText(QApplication::translate("WebcamControl", "Exit", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(WebcamControl);
    } // retranslateUi

};

namespace Ui {
    class WebcamControl: public Ui_WebcamControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBCAMCONTROL_H
