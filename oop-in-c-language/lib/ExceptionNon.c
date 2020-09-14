#include"ExceptionNon.h"

Status Exception_NonException_DefaultHandler(const UT exception);

Exception Exception_NonException_Table[Exception_NonException_Total] = {

    [Exception_NonException - Exception_NonException_Base] = {
        .Tag = Exception_NonException,
        .Name = "NonException",
        .Message = "Non Exception",
        .Handler = &Exception_NonException_DefaultHandler
    },
    [Exception_ResumeException - Exception_NonException_Base] = {
        .Tag = Exception_ResumeException,
        .Name = "ResumeException",
        .Message = "Resume Exception",
        .Handler = &Exception_NonException_DefaultHandler
    }
};

//Status Exception_NonException_Init(){
//
//    UT i;
//    for(i = 0; i < Exception_NonException_Total; i++) {
//        switch(i + Exception_NonException_Base) {
//            case Exception_ResumeException:
//                Exception_NonException_Table[i].Tag = i + Exception_NonException_Base;
//                Exception_NonException_Table[i].Name = "ResumeException";
//                Exception_NonException_Table[i].Message = "Resume Exception";
//                Exception_NonException_Table[i].Handler = &Exception_NonException_DefaultHandler;
//                break;
//            default:
//                Exception_NonException_Table[i].Tag = i + Exception_NonException_Base;
//                Exception_NonException_Table[i].Name = "NonException";
//                Exception_NonException_Table[i].Message = "Non Exception";
//                Exception_NonException_Table[i].Handler = &Exception_NonException_DefaultHandler;
//        }
//    }
//
//    return SUCCESS;
//}

Status Exception_NonException_DefaultHandler(const UT exception){
    if((exception < Exception_NonException_Base) || (exception > (Exception_NonException_Base + Exception_NonException_Total))) {
        return FAILURE;
    }
    //空
    return SUCCESS;
}
