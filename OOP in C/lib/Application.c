#include"Application.h"

Status Application_Initialize(){

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(1,1),&wsaData)!=0){
        printf("WSAStartup Error!\n");
        return 0;
    }
    Exception_Init();

    return SUCCESS;
}

Status Application_Finalize(){

    WSACleanup();

    return SUCCESS;
}
