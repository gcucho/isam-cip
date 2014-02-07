/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QComboBox *cb_trygpu;
    QLabel *l_tryGPU;
    QLabel *l_workmegapix;
    QLineEdit *le_wmpx;
    QLabel *label;
    QGroupBox *groupBox_2;
    QPushButton *pb_addimage;
    QPushButton *pb_deleteitem;
    QPushButton *pb_deleteall;
    QLabel *l_addimage;
    QLabel *l_deleteitem;
    QLabel *l_deleteall;
    QFrame *frame;
    QListView *lst_imagefile;
    QPushButton *pb_generate;
    QLabel *l_generate;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(512, 413);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 181, 361));
        cb_trygpu = new QComboBox(groupBox);
        cb_trygpu->setObjectName(QStringLiteral("cb_trygpu"));
        cb_trygpu->setGeometry(QRect(90, 30, 69, 22));
        cb_trygpu->setEditable(false);
        l_tryGPU = new QLabel(groupBox);
        l_tryGPU->setObjectName(QStringLiteral("l_tryGPU"));
        l_tryGPU->setGeometry(QRect(20, 30, 61, 16));
        l_workmegapix = new QLabel(groupBox);
        l_workmegapix->setObjectName(QStringLiteral("l_workmegapix"));
        l_workmegapix->setGeometry(QRect(20, 60, 61, 16));
        le_wmpx = new QLineEdit(groupBox);
        le_wmpx->setObjectName(QStringLiteral("le_wmpx"));
        le_wmpx->setGeometry(QRect(90, 60, 71, 20));
        le_wmpx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 10, 211, 16));
        label->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(200, 40, 301, 361));
        pb_addimage = new QPushButton(groupBox_2);
        pb_addimage->setObjectName(QStringLiteral("pb_addimage"));
        pb_addimage->setGeometry(QRect(20, 20, 61, 61));
        pb_deleteitem = new QPushButton(groupBox_2);
        pb_deleteitem->setObjectName(QStringLiteral("pb_deleteitem"));
        pb_deleteitem->setGeometry(QRect(90, 20, 61, 61));
        pb_deleteall = new QPushButton(groupBox_2);
        pb_deleteall->setObjectName(QStringLiteral("pb_deleteall"));
        pb_deleteall->setGeometry(QRect(160, 20, 61, 61));
        l_addimage = new QLabel(groupBox_2);
        l_addimage->setObjectName(QStringLiteral("l_addimage"));
        l_addimage->setGeometry(QRect(20, 80, 61, 16));
        l_addimage->setAlignment(Qt::AlignCenter);
        l_deleteitem = new QLabel(groupBox_2);
        l_deleteitem->setObjectName(QStringLiteral("l_deleteitem"));
        l_deleteitem->setGeometry(QRect(90, 80, 61, 16));
        l_deleteitem->setAlignment(Qt::AlignCenter);
        l_deleteall = new QLabel(groupBox_2);
        l_deleteall->setObjectName(QStringLiteral("l_deleteall"));
        l_deleteall->setGeometry(QRect(160, 80, 61, 16));
        l_deleteall->setAlignment(Qt::AlignCenter);
        frame = new QFrame(groupBox_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 190, 271, 161));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        lst_imagefile = new QListView(groupBox_2);
        lst_imagefile->setObjectName(QStringLiteral("lst_imagefile"));
        lst_imagefile->setGeometry(QRect(20, 110, 271, 71));
        pb_generate = new QPushButton(groupBox_2);
        pb_generate->setObjectName(QStringLiteral("pb_generate"));
        pb_generate->setGeometry(QRect(230, 20, 61, 61));
        l_generate = new QLabel(groupBox_2);
        l_generate->setObjectName(QStringLiteral("l_generate"));
        l_generate->setGeometry(QRect(230, 80, 61, 16));
        l_generate->setAlignment(Qt::AlignCenter);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Image Stitching", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "Parameters", 0));
        l_tryGPU->setText(QApplication::translate("Dialog", "Try GPU:", 0));
        l_workmegapix->setText(QApplication::translate("Dialog", "Work Mpx:", 0));
        le_wmpx->setText(QApplication::translate("Dialog", "0.6", 0));
        label->setText(QApplication::translate("Dialog", "IMAGE STITCHING V1.0", 0));
        groupBox_2->setTitle(QApplication::translate("Dialog", "Select Images", 0));
        pb_addimage->setText(QString());
        pb_deleteitem->setText(QString());
        pb_deleteall->setText(QString());
        l_addimage->setText(QApplication::translate("Dialog", "Add Image", 0));
        l_deleteitem->setText(QApplication::translate("Dialog", "Delete Item", 0));
        l_deleteall->setText(QApplication::translate("Dialog", "Delete All", 0));
        pb_generate->setText(QString());
        l_generate->setText(QApplication::translate("Dialog", "Generate", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
