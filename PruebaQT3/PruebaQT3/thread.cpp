#include "thread.h"
#include "main.h"
#include "structures.h"
#include <QMessageBox>

Thread::Thread(QObject *parent) :
    QThread(parent)
{
}

void Thread::run()
{
   // Main process//
    emit valueDisplayChanged(2);
    int * error;
    error = new int();

    if(myStitch.MainProcess(error))
    {
      emit valueDisplayChanged(3);
    }
    else if(*error == 1) emit valueDisplayChanged(10); //Not enough correlated images
    else if(*error == 2) emit valueDisplayChanged(11);
    else if(*error == 3) emit valueDisplayChanged(12);
    else if(*error == 4) emit valueDisplayChanged(13);
    else emit valueDisplayChanged(14); // General error!



}

void Thread::UpdateParams(DataParam * dataParamDlg)
{
    // Copying Params from QThread to Stitching Class
    if (myStitch.SetParameters(dataParamDlg))
    {
        emit valueDisplayChanged(0);
        emit valueDisplayChanged(1);
    }
}
