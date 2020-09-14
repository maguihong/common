#ifndef __EXCEPTION_CONFIG_H
#define __EXCEPTION_CONFIG_H

#include"Type.h"

typedef struct Exception {
    UT Tag;
    C* Name;
    C* Message;
    Status (*Handler)(const UT exception);
} Exception;


#define Exception_NonException_Base             0
#define Exception_RuntimeException_Base         100
#define Exception_IOException_Base              1000
#define Exception_NetworkException_Base         2000

#define Exception_BufferSize     4096


#endif // __EXCEPTION_CONFIG_H
