#ifndef __EXCEPTION_RUNTIME_H
#define __EXCEPTION_RUNTIME_H

#include"Type.h"
#include"ExceptionConfig.h"

#define Exception_RuntimeException_Total                4 // 异常总数
#define Exception_RuntimeException                      Exception_RuntimeException_Base
#define Exception_ArrayIndexOutOfBoundsException        (Exception_RuntimeException_Base + 1)
#define Exception_IllegalArgumentException              (Exception_RuntimeException_Base + 2)
#define Exception_NullPointerException                  (Exception_RuntimeException_Base + 3)

extern Exception Exception_RuntimeException_Table[Exception_RuntimeException_Total];

//Status Exception_RuntimeException_Init();


#endif // __EXCEPTION_RUNTIME_H
