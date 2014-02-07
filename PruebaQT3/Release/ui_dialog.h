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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QComboBox *cb_trygpu;
    QLabel *l_tryGPU;
    QLabel *l_workmegapix;
    QLineEdit *le_wmpx;
    QLabel *l_mtch;
    QLineEdit *le_match;
    QLabel *l_thrsh;
    QLineEdit *le_confthrsh;
    QLabel *label_2;
    QComboBox *cb_bundleadj;
    QLabel *label_3;
    QLineEdit *le_bamask;
    QLabel *label_4;
    QComboBox *cb_wavecorrect;
    QLabel *label_5;
    QLineEdit *le_savegrph;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QFrame *line;
    QLabel *label_12;
    QLabel *label_13;
    QFrame *line_2;
    QComboBox *cb_warp;
    QLineEdit *le_seammpx;
    QComboBox *cb_seam;
    QLineEdit *le_compsmpx;
    QComboBox *cb_expocomp;
    QLineEdit *le_blendstrn;
    QComboBox *cb_blend;
    QLineEdit *le_output;
    QLabel *l_title;
    QGroupBox *groupBox_2;
    QPushButton *pb_addimage;
    QPushButton *pb_deleteitem;
    QPushButton *pb_deleteall;
    QLabel *l_addimage;
    QLabel *l_deleteitem;
    QLabel *l_deleteall;
    QPushButton *pb_generate;
    QLabel *l_generate;
    QPushButton *pb_showresult;
    QLabel *l_showresult;
    QGroupBox *groupBox_3;
    QListView *lst_imagefile;
    QGroupBox *groupBox_4;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox_5;
    QTextEdit *te_display;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setEnabled(true);
        Dialog->resize(608, 609);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/pictures.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setSizeGripEnabled(false);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 221, 551));
        cb_trygpu = new QComboBox(groupBox);
        cb_trygpu->setObjectName(QStringLiteral("cb_trygpu"));
        cb_trygpu->setEnabled(false);
        cb_trygpu->setGeometry(QRect(120, 30, 81, 22));
        cb_trygpu->setEditable(false);
        l_tryGPU = new QLabel(groupBox);
        l_tryGPU->setObjectName(QStringLiteral("l_tryGPU"));
        l_tryGPU->setGeometry(QRect(20, 30, 61, 16));
        l_workmegapix = new QLabel(groupBox);
        l_workmegapix->setObjectName(QStringLiteral("l_workmegapix"));
        l_workmegapix->setGeometry(QRect(20, 80, 61, 16));
        le_wmpx = new QLineEdit(groupBox);
        le_wmpx->setObjectName(QStringLiteral("le_wmpx"));
        le_wmpx->setGeometry(QRect(120, 80, 81, 20));
        le_wmpx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        le_wmpx->setReadOnly(false);
        l_mtch = new QLabel(groupBox);
        l_mtch->setObjectName(QStringLiteral("l_mtch"));
        l_mtch->setGeometry(QRect(20, 110, 71, 16));
        le_match = new QLineEdit(groupBox);
        le_match->setObjectName(QStringLiteral("le_match"));
        le_match->setGeometry(QRect(120, 110, 81, 20));
        le_match->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_thrsh = new QLabel(groupBox);
        l_thrsh->setObjectName(QStringLiteral("l_thrsh"));
        l_thrsh->setGeometry(QRect(20, 140, 71, 16));
        le_confthrsh = new QLineEdit(groupBox);
        le_confthrsh->setObjectName(QStringLiteral("le_confthrsh"));
        le_confthrsh->setGeometry(QRect(120, 140, 81, 20));
        le_confthrsh->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 170, 71, 16));
        cb_bundleadj = new QComboBox(groupBox);
        cb_bundleadj->setObjectName(QStringLiteral("cb_bundleadj"));
        cb_bundleadj->setGeometry(QRect(120, 170, 81, 22));
        cb_bundleadj->setEditable(false);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 200, 91, 16));
        le_bamask = new QLineEdit(groupBox);
        le_bamask->setObjectName(QStringLiteral("le_bamask"));
        le_bamask->setGeometry(QRect(120, 200, 81, 20));
        le_bamask->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 230, 91, 16));
        cb_wavecorrect = new QComboBox(groupBox);
        cb_wavecorrect->setObjectName(QStringLiteral("cb_wavecorrect"));
        cb_wavecorrect->setGeometry(QRect(120, 230, 81, 22));
        cb_wavecorrect->setEditable(false);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 260, 81, 16));
        le_savegrph = new QLineEdit(groupBox);
        le_savegrph->setObjectName(QStringLiteral("le_savegrph"));
        le_savegrph->setGeometry(QRect(122, 260, 81, 20));
        le_savegrph->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 300, 81, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 330, 91, 16));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 360, 81, 16));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 390, 101, 16));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 420, 71, 16));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 450, 81, 16));
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 280, 201, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 480, 91, 16));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 510, 61, 16));
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 60, 201, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        cb_warp = new QComboBox(groupBox);
        cb_warp->setObjectName(QStringLiteral("cb_warp"));
        cb_warp->setGeometry(QRect(120, 300, 81, 22));
        cb_warp->setEditable(false);
        le_seammpx = new QLineEdit(groupBox);
        le_seammpx->setObjectName(QStringLiteral("le_seammpx"));
        le_seammpx->setGeometry(QRect(120, 330, 81, 20));
        le_seammpx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        le_seammpx->setReadOnly(false);
        cb_seam = new QComboBox(groupBox);
        cb_seam->setObjectName(QStringLiteral("cb_seam"));
        cb_seam->setGeometry(QRect(120, 360, 81, 22));
        cb_seam->setEditable(false);
        le_compsmpx = new QLineEdit(groupBox);
        le_compsmpx->setObjectName(QStringLiteral("le_compsmpx"));
        le_compsmpx->setGeometry(QRect(120, 390, 81, 20));
        le_compsmpx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        le_compsmpx->setReadOnly(false);
        cb_expocomp = new QComboBox(groupBox);
        cb_expocomp->setObjectName(QStringLiteral("cb_expocomp"));
        cb_expocomp->setGeometry(QRect(120, 420, 81, 22));
        cb_expocomp->setEditable(false);
        le_blendstrn = new QLineEdit(groupBox);
        le_blendstrn->setObjectName(QStringLiteral("le_blendstrn"));
        le_blendstrn->setGeometry(QRect(120, 480, 81, 20));
        le_blendstrn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        le_blendstrn->setReadOnly(false);
        cb_blend = new QComboBox(groupBox);
        cb_blend->setObjectName(QStringLiteral("cb_blend"));
        cb_blend->setGeometry(QRect(120, 450, 81, 22));
        cb_blend->setEditable(false);
        le_output = new QLineEdit(groupBox);
        le_output->setObjectName(QStringLiteral("le_output"));
        le_output->setGeometry(QRect(120, 510, 81, 20));
        le_output->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_title = new QLabel(Dialog);
        l_title->setObjectName(QStringLiteral("l_title"));
        l_title->setGeometry(QRect(80, 10, 381, 31));
        l_title->setAlignment(Qt::AlignCenter);
        l_title->setWordWrap(false);
        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(240, 50, 361, 111));
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pb_addimage = new QPushButton(groupBox_2);
        pb_addimage->setObjectName(QStringLiteral("pb_addimage"));
        pb_addimage->setGeometry(QRect(10, 20, 61, 61));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/picture_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_addimage->setIcon(icon1);
        pb_addimage->setIconSize(QSize(32, 32));
        pb_addimage->setAutoDefault(true);
        pb_addimage->setDefault(false);
        pb_deleteitem = new QPushButton(groupBox_2);
        pb_deleteitem->setObjectName(QStringLiteral("pb_deleteitem"));
        pb_deleteitem->setGeometry(QRect(80, 20, 61, 61));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/picture_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_deleteitem->setIcon(icon2);
        pb_deleteitem->setIconSize(QSize(32, 32));
        pb_deleteall = new QPushButton(groupBox_2);
        pb_deleteall->setObjectName(QStringLiteral("pb_deleteall"));
        pb_deleteall->setGeometry(QRect(150, 20, 61, 61));
        pb_deleteall->setIcon(icon);
        pb_deleteall->setIconSize(QSize(32, 32));
        l_addimage = new QLabel(groupBox_2);
        l_addimage->setObjectName(QStringLiteral("l_addimage"));
        l_addimage->setGeometry(QRect(10, 80, 61, 16));
        l_addimage->setAlignment(Qt::AlignCenter);
        l_deleteitem = new QLabel(groupBox_2);
        l_deleteitem->setObjectName(QStringLiteral("l_deleteitem"));
        l_deleteitem->setGeometry(QRect(80, 80, 61, 16));
        l_deleteitem->setAlignment(Qt::AlignCenter);
        l_deleteall = new QLabel(groupBox_2);
        l_deleteall->setObjectName(QStringLiteral("l_deleteall"));
        l_deleteall->setGeometry(QRect(150, 80, 61, 16));
        l_deleteall->setAlignment(Qt::AlignCenter);
        pb_generate = new QPushButton(groupBox_2);
        pb_generate->setObjectName(QStringLiteral("pb_generate"));
        pb_generate->setGeometry(QRect(220, 20, 61, 61));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/map_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_generate->setIcon(icon3);
        pb_generate->setIconSize(QSize(32, 32));
        l_generate = new QLabel(groupBox_2);
        l_generate->setObjectName(QStringLiteral("l_generate"));
        l_generate->setGeometry(QRect(220, 80, 61, 16));
        l_generate->setAlignment(Qt::AlignCenter);
        pb_showresult = new QPushButton(groupBox_2);
        pb_showresult->setObjectName(QStringLiteral("pb_showresult"));
        pb_showresult->setGeometry(QRect(290, 20, 61, 61));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/map_magnify.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_showresult->setIcon(icon4);
        pb_showresult->setIconSize(QSize(32, 32));
        l_showresult = new QLabel(groupBox_2);
        l_showresult->setObjectName(QStringLiteral("l_showresult"));
        l_showresult->setGeometry(QRect(290, 80, 61, 16));
        groupBox_3 = new QGroupBox(Dialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(240, 170, 361, 91));
        groupBox_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lst_imagefile = new QListView(groupBox_3);
        lst_imagefile->setObjectName(QStringLiteral("lst_imagefile"));
        lst_imagefile->setEnabled(true);
        lst_imagefile->setGeometry(QRect(10, 20, 341, 61));
        lst_imagefile->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lst_imagefile->setWordWrap(true);
        lst_imagefile->setSelectionRectVisible(false);
        groupBox_4 = new QGroupBox(Dialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(240, 270, 361, 251));
        groupBox_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        graphicsView = new QGraphicsView(groupBox_4);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 341, 221));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));
        graphicsView->raise();
        groupBox_5 = new QGroupBox(Dialog);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(240, 530, 361, 71));
        groupBox_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        te_display = new QTextEdit(groupBox_5);
        te_display->setObjectName(QStringLiteral("te_display"));
        te_display->setGeometry(QRect(10, 20, 341, 41));
        te_display->setReadOnly(true);
        te_display->raise();

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
        l_mtch->setText(QApplication::translate("Dialog", "Match Conf.:", 0));
        le_match->setText(QApplication::translate("Dialog", "0.3", 0));
        l_thrsh->setText(QApplication::translate("Dialog", "Conf. Thresh.:", 0));
        le_confthrsh->setText(QApplication::translate("Dialog", "1", 0));
        label_2->setText(QApplication::translate("Dialog", "Bundle Adj.:", 0));
        label_3->setText(QApplication::translate("Dialog", "Bundle Adj. Msk.:", 0));
        le_bamask->setText(QApplication::translate("Dialog", "XXXXX", 0));
        label_4->setText(QApplication::translate("Dialog", "Wave Correct.:", 0));
        label_5->setText(QApplication::translate("Dialog", "Save Graph:", 0));
        le_savegrph->setText(QApplication::translate("Dialog", "outgraph.txt", 0));
        label_6->setText(QApplication::translate("Dialog", "Warp:", 0));
        label_7->setText(QApplication::translate("Dialog", "Seam Megapix:", 0));
        label_8->setText(QApplication::translate("Dialog", "Seam:", 0));
        label_9->setText(QApplication::translate("Dialog", "Compose Megapix:", 0));
        label_10->setText(QApplication::translate("Dialog", "Expos Comp.:", 0));
        label_11->setText(QApplication::translate("Dialog", "Blend:", 0));
        label_12->setText(QApplication::translate("Dialog", "Blend Strength:", 0));
        label_13->setText(QApplication::translate("Dialog", "Output:", 0));
        le_seammpx->setText(QApplication::translate("Dialog", "0.1", 0));
        le_compsmpx->setText(QApplication::translate("Dialog", "-1", 0));
        le_blendstrn->setText(QApplication::translate("Dialog", "5", 0));
        le_output->setText(QApplication::translate("Dialog", "result.bmp", 0));
        l_title->setText(QApplication::translate("Dialog", "IMAGE STITCHING V1.0     CIP-LIMA", 0));
        groupBox_2->setTitle(QApplication::translate("Dialog", "Controls", 0));
#ifndef QT_NO_TOOLTIP
        pb_addimage->setToolTip(QApplication::translate("Dialog", "Add Image", 0));
#endif // QT_NO_TOOLTIP
        pb_addimage->setText(QString());
        pb_deleteitem->setText(QString());
        pb_deleteall->setText(QString());
        l_addimage->setText(QApplication::translate("Dialog", "Add Image", 0));
        l_deleteitem->setText(QApplication::translate("Dialog", "Delete Item", 0));
        l_deleteall->setText(QApplication::translate("Dialog", "Delete All", 0));
        pb_generate->setText(QString());
        l_generate->setText(QApplication::translate("Dialog", "Generate", 0));
        pb_showresult->setText(QString());
        l_showresult->setText(QApplication::translate("Dialog", "Show Result", 0));
        groupBox_3->setTitle(QApplication::translate("Dialog", "Selected Images", 0));
        groupBox_4->setTitle(QApplication::translate("Dialog", "Image", 0));
        groupBox_5->setTitle(QApplication::translate("Dialog", "Status", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
