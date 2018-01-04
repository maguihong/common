#include"ExceptionIO.h"

Status Exception_IOException_DefaultHandler(const UT exception);

Exception Exception_IOException_Table[Exception_IOException_Total] = {

    [Exception_IOException - Exception_IOException_Base] = {
        .Tag = Exception_IOException,
        .Name = "IOException",
        .Message = "IO Exception",
        .Handler = &Exception_IOException_DefaultHandler
    }
};


//Status Exception_IOException_Init(){
//
//    UT i;
//    for(i = 0; i < Exception_IOException_Total; i++) {
//        switch(i + Exception_IOException_Base) {
//            default:
//                Exception_IOException_Table[i].Tag = i + Exception_IOException_Base;
//                Exception_IOException_Table[i].Name = "IOException";
//                Exception_IOException_Table[i].Message = "IO Exception";
//                Exception_IOException_Table[i].Handler = &Exception_IOException_DefaultHandler;
//        }
//    }
//
//    return SUCCESS;
//}

Status Exception_IOException_DefaultHandler(const UT exception){
    if((exception < Exception_IOException_Base) || (exception > (Exception_IOException_Base + Exception_IOException_Total))) {
        return FAILURE;
    }
    //空
    return SUCCESS;
}
