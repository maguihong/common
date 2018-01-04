#ifndef __EXCEPTION_IO_H
#define __EXCEPTION_IO_H

#include"Type.h"
#include"ExceptionConfig.h"

#define Exception_IOException_Total             1 // 异常总数
#define Exception_IOException                   Exception_IOException_Base

extern Exception Exception_IOException_Table[Exception_IOException_Total];

//Status Exception_IOException_Init();

#endif // __EXCEPTION_IO_H
