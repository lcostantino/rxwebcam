/********************************************************************************
** Form generated from reading ui file 'streaming.ui'
**
** Created: Sun Nov 2 17:16:34 2008
**      by: Qt User Interface Compiler version 4.4.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STREAMING_H
#define UI_STREAMING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormStreaming
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_stream;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_start;
    QPushButton *pb_stop;
    QPushButton *pb_capture;
    QPushButton *pb_movie;

    void setupUi(QWidget *FormStreaming)
    {
    if (FormStreaming->objectName().isEmpty())
        FormStreaming->setObjectName(QString::fromUtf8("FormStreaming"));
    FormStreaming->resize(540, 253);
    QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(FormStreaming->sizePolicy().hasHeightForWidth());
    FormStreaming->setSizePolicy(sizePolicy);
    FormStreaming->setMaximumSize(QSize(5555, 5555));
    gridLayout = new QGridLayout(FormStreaming);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    frame_stream = new QFrame(FormStreaming);
    frame_stream->setObjectName(QString::fromUtf8("frame_stream"));
    QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(frame_stream->sizePolicy().hasHeightForWidth());
    frame_stream->setSizePolicy(sizePolicy1);
    frame_stream->setMaximumSize(QSize(1639, 1111));
    frame_stream->setFrameShape(QFrame::StyledPanel);
    frame_stream->setFrameShadow(QFrame::Raised);
    frame_stream->setLineWidth(4);

    gridLayout->addWidget(frame_stream, 0, 0, 1, 5);

    horizontalSpacer = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

    pb_start = new QPushButton(FormStreaming);
    pb_start->setObjectName(QString::fromUtf8("pb_start"));
    QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(pb_start->sizePolicy().hasHeightForWidth());
    pb_start->setSizePolicy(sizePolicy2);
    pb_start->setAutoFillBackground(false);
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8(":/proyect/qt4/iconos/start.png")), QIcon::Normal, QIcon::Off);
    pb_start->setIcon(icon);
    pb_start->setIconSize(QSize(40, 36));
    pb_start->setFlat(true);

    gridLayout->addWidget(pb_start, 1, 1, 1, 1);

    pb_stop = new QPushButton(FormStreaming);
    pb_stop->setObjectName(QString::fromUtf8("pb_stop"));
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8(":/proyect/qt4/iconos/stop.png")), QIcon::Normal, QIcon::Off);
    pb_stop->setIcon(icon1);
    pb_stop->setIconSize(QSize(40, 36));
    pb_stop->setFlat(true);

    gridLayout->addWidget(pb_stop, 1, 2, 1, 1);

    pb_capture = new QPushButton(FormStreaming);
    pb_capture->setObjectName(QString::fromUtf8("pb_capture"));
    QIcon icon2;
    icon2.addPixmap(QPixmap(QString::fromUtf8(":/proyect/qt4/iconos/capturar.png")), QIcon::Normal, QIcon::Off);
    pb_capture->setIcon(icon2);
    pb_capture->setIconSize(QSize(40, 36));
    pb_capture->setFlat(true);

    gridLayout->addWidget(pb_capture, 1, 3, 1, 1);

    pb_movie = new QPushButton(FormStreaming);
    pb_movie->setObjectName(QString::fromUtf8("pb_movie"));
    QIcon icon3;
    icon3.addPixmap(QPixmap(QString::fromUtf8(":/proyect/qt4/iconos/kplato.png")), QIcon::Normal, QIcon::Off);
    pb_movie->setIcon(icon3);
    pb_movie->setIconSize(QSize(40, 36));
    pb_movie->setFlat(true);

    gridLayout->addWidget(pb_movie, 1, 4, 1, 1);


    retranslateUi(FormStreaming);

    QMetaObject::connectSlotsByName(FormStreaming);
    } // setupUi

    void retranslateUi(QWidget *FormStreaming)
    {
    FormStreaming->setWindowTitle(QApplication::translate("FormStreaming", "Form", 0, QApplication::UnicodeUTF8));
    pb_start->setText(QString());
    pb_stop->setText(QString());
    pb_capture->setText(QString());
    pb_movie->setText(QString());
    Q_UNUSED(FormStreaming);
    } // retranslateUi

};

namespace Ui {
    class FormStreaming: public Ui_FormStreaming {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREAMING_H
