#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include "structures.h"
#include <iostream>


#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

class DLL_EXPORT Stitching{

private:


public:
    DataParam dataParamDLL;
    Stitching();
    ~Stitching();
    bool SetParameters(DataParam*);
    bool SaveParameters(void);
    int test(int x);
    bool MainProcess(int*);
};

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
