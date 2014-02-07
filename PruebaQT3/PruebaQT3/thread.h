#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include "main.h"
#include "structures.h"

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = 0);
    Stitching myStitch;

signals:
    void valueDisplayChanged(int);

public slots:
    void UpdateParams(DataParam *dataParamDlg);

private:
    void run();
};

#endif // THREAD_H
