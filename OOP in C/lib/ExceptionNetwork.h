#ifndef __EXCEPTION_NETWORK_H
#define __EXCEPTION_NETWORK_H

#include"Type.h"
#include"ExceptionConfig.h"

#define Exception_NetworkException_Total                12 // 异常总数
#define Exception_NetworkException                      Exception_NetworkException_Base
#define Exception_SocketCreateFailException             (Exception_NetworkException_Base + 1)
#define Exception_SocketConnectFailException            (Exception_NetworkException_Base + 2)
#define Exception_SocketBindFailException               (Exception_NetworkException_Base + 3)
#define Exception_SocketListenFailException             (Exception_NetworkException_Base + 4)
#define Exception_SocketAcceptFailException             (Exception_NetworkException_Base + 5)
#define Exception_SocketReceiveFailException            (Exception_NetworkException_Base + 6)
#define Exception_SocketSendFailException               (Exception_NetworkException_Base + 7)
#define Exception_IllegalSocketAddressException         (Exception_NetworkException_Base + 8)
#define Exception_SocketAddressTransformFailException   (Exception_NetworkException_Base + 9)
#define Exception_SocketSetOptionFailException          (Exception_NetworkException_Base + 10)
#define Exception_SocketGetOptionFailException          (Exception_NetworkException_Base + 11)

extern Exception Exception_NetworkException_Table[Exception_NetworkException_Total];

//Status Exception_NetworkException_Init();


#endif // __EXCEPTION_NETWORK_H
