#ifndef __EXCEPTION_NON_H
#define __EXCEPTION_NON_H

#include"Type.h"
#include"ExceptionConfig.h"

#define Exception_NonException_Total        2
#define Exception_NonException              Exception_NonException_Base
#define Exception_ResumeException           (Exception_NonException + 1)

extern Exception Exception_NonException_Table[Exception_NonException_Total];

//Status Exception_NonException_Init();


#endif // __EXCEPTION_NON_H
