#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QStringList>
#include <QStringListModel>
#include <QGraphicsScene>
#include <fstream>
#include <string>
#include <vector>
#include "thread.h"
#include "structures.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
//public slots:
   // void test(void);

signals:
    void ParamsChanged(DataParam *);

private slots:
    void on_pb_addimage_clicked();

    void on_pb_deleteitem_clicked();

    void on_pb_deleteall_clicked();

    void on_pb_generate_clicked();

    void on_lst_imagefile_clicked(const QModelIndex &index);

    void UpdateDisplay(int);

    void on_pb_showresult_clicked();

private:
    Ui::Dialog *ui;
    QStringList m_slData;
    QGraphicsScene *scene;
    Thread *mythread;
    DataParam *dataParam;

};

#endif // DIALOG_H
