#include"ExceptionNetwork.h"

Status Exception_NetworkException_DefaultHandler(const UT exception);

Exception Exception_NetworkException_Table[Exception_NetworkException_Total] = {

    [Exception_IllegalSocketAddressException - Exception_NetworkException_Base] = {
        .Tag = Exception_IllegalSocketAddressException,
        .Name = "IllegalSocketAddressException",
        .Message = "Illegal Socket Address",
        .Handler = &Exception_NetworkException_DefaultHandler
    },
    [Exception_NetworkException - Exception_NetworkException_Base] = {
        .Tag = Exception_NetworkException,
        .Name = "NetworkException",
        .Message = "Network Exception",
        .Handler = &Exception_NetworkException_DefaultHandler
    },
    [Exception_SocketAcceptFailException - Exception_NetworkException_Base] = {
        .Tag = Exception_SocketAcceptFailException,
        .Name = "SocketAcceptFailException",
        .Message = "Socket Accept Fail",
        .Handler = &Exception_NetworkException_DefaultHandler
    },
    [Exception_SocketAddressTransformFailException - Exception_NetworkException_Base] = {
        .Tag = Exception_SocketAddressTransformFailException,
        .Name = "SocketAddressTransformFailException",
        .Message = "SocketAddress Transform Fail",
        .Handler = &Exception_NetworkException_DefaultHandler
    },
    [Exception_SocketBindFailException - Exception_NetworkException_Base] = {
        .Tag = Exception_SocketBindFailException,
        .Name = "SocketBindFailException",
        .Message = "Socket Bind Fail",
        .Handler = &Exception_NetworkException_DefaultHandler
    },
    [Exception_SocketConnectFailException - Exception_NetworkException_Base] = {
        .Tag = Exception_SocketConnectFailException,
        .Name = "SocketConnectFailedException",
        .Message = "Socket Connect Fail",
        .Handler = &Exception_NetworkException_DefaultHandler
    },
    [Exception_SocketCreateFailException - Exception_NetworkException_Base] = {
        .Tag = Exception_SocketCreateFailException,
        .Name = "SocketCreateFailedException",
        .Message = "Socket Create Fail",
        .Handler = &Exception_NetworkException_DefaultHandler
    },
    [Exception_SocketGetOptionFailException - Exception_NetworkException_Base] = {
        .Tag = Exception_SocketGetOptionFailException,
        .Name = "SocketGetOptionFailException",
        .Message = "Socket Get Option Fail",
        .Handler = &Exception_NetworkException_DefaultHandler
    },
    [Exception_SocketListenFailException - Exception_NetworkException_Base] = {
        .Tag = Exception_SocketListenFailException,
        .Name = "SocketListenFailException",
        .Message = "Socket Listen Fail",
        .Handler = &Exception_NetworkException_DefaultHandler
    },
    [Exception_SocketReceiveFailException - Exception_NetworkException_Base] = {
        .Tag = Exception_SocketReceiveFailException,
        .Name = "SocketReceiveFailException",
        .Message = "Socket Receive Fail",
        .Handler = &Exception_NetworkException_DefaultHandler
    },
    [Exception_SocketSendFailException - Exception_NetworkException_Base] = {
        .Tag = Exception_SocketSendFailException,
        .Name = "SocketSendFailException",
        .Message = "Socket Send Fail",
        .Handler = &Exception_NetworkException_DefaultHandler
    },
    [Exception_SocketSetOptionFailException - Exception_NetworkException_Base] = {
        .Tag = Exception_SocketSetOptionFailException,
        .Name = "SocketSetOptionFailException",
        .Message = "Socket Set Option Fail",
        .Handler = &Exception_NetworkException_DefaultHandler
    }
};

//Status Exception_NetworkException_Init(){
//
//    UT i;
//    for(i = 0; i < Exception_NetworkException_Total; i++) {
//        switch(i + Exception_NetworkException_Base) {
//            case Exception_IllegalSocketAddressException:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "IllegalSocketAddressException";
//                Exception_NetworkException_Table[i].Message = "Illegal Socket Address";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//                break;
//            case Exception_SocketAcceptFailException:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "SocketAcceptFailException";
//                Exception_NetworkException_Table[i].Message = "Socket Accept Fail";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//                break;
//            case Exception_SocketAddressTransformFailException:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "SocketAddressTransformFailException";
//                Exception_NetworkException_Table[i].Message = "SocketAddress Transform Fail";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//                break;
//            case Exception_SocketBindFailException:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "SocketBindFailException";
//                Exception_NetworkException_Table[i].Message = "Socket Bind Fail";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//                break;
//            case Exception_SocketConnectFailException:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "SocketConnectFailedException";
//                Exception_NetworkException_Table[i].Message = "Socket Connect Fail";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//                break;
//            case Exception_SocketCreateFailException:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "SocketCreateFailedException";
//                Exception_NetworkException_Table[i].Message = "Socket Create Fail";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//                break;
//            case Exception_SocketGetOptionFailException:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "SocketGetOptionFailException";
//                Exception_NetworkException_Table[i].Message = "Socket Get Option Fail";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//                break;
//            case Exception_SocketListenFailException:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "SocketListenFailException";
//                Exception_NetworkException_Table[i].Message = "Socket Listen Fail";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//                break;
//            case Exception_SocketReceiveFailException:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "SocketReceiveFailException";
//                Exception_NetworkException_Table[i].Message = "Socket Receive Fail";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//                break;
//            case Exception_SocketSendFailException:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "SocketSendFailException";
//                Exception_NetworkException_Table[i].Message = "Socket Send Fail";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//                break;
//            case Exception_SocketSetOptionFailException:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "SocketSetOptionFailException";
//                Exception_NetworkException_Table[i].Message = "Socket Set Option Fail";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//                break;
//            default:
//                Exception_NetworkException_Table[i].Tag = i + Exception_NetworkException_Base;
//                Exception_NetworkException_Table[i].Name = "NetworkException";
//                Exception_NetworkException_Table[i].Message = "Network Exception";
//                Exception_NetworkException_Table[i].Handler = &Exception_NetworkException_DefaultHandler;
//        }
//    }
//
//    return SUCCESS;
//}

Status Exception_NetworkException_DefaultHandler(const UT exception){
    if((exception < Exception_NetworkException_Base) || (exception > (Exception_NetworkException_Base + Exception_NetworkException_Total))) {
        return FAILURE;
    }
    //空
    return SUCCESS;
}
