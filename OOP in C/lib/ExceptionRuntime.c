#include"ExceptionRuntime.h"

Status Exception_RuntimeException_DefaultHandler(const UT exception);

Exception Exception_RuntimeException_Table[Exception_RuntimeException_Total] = {

    [Exception_ArrayIndexOutOfBoundsException - Exception_RuntimeException_Base] = {
        .Tag = Exception_ArrayIndexOutOfBoundsException,
        .Name = "ArrayIndexOutOfBoundsException",
        .Message = "Array Index Out Of Bounds",
        .Handler = &Exception_RuntimeException_DefaultHandler
    },
    [Exception_IllegalArgumentException - Exception_RuntimeException_Base] = {
        .Tag = Exception_IllegalArgumentException,
        .Name = "IllegalArgumentException",
        .Message = "Illegal Argument",
        .Handler = &Exception_RuntimeException_DefaultHandler
    },
    [Exception_NullPointerException - Exception_RuntimeException_Base] = {
        .Tag = Exception_NullPointerException,
        .Name = "NullPointerException",
        .Message = "Null Pointer",
        .Handler = &Exception_RuntimeException_DefaultHandler
    },
    [Exception_RuntimeException - Exception_RuntimeException_Base] = {
        .Tag = Exception_RuntimeException,
        .Name = "RuntimeException",
        .Message = "Runtime Exception",
        .Handler = &Exception_RuntimeException_DefaultHandler
    }
};

//Status Exception_RuntimeException_Init(){
//
//    UT i;
//    for(i = 0; i < Exception_RuntimeException_Total; i++) {
//        switch(i + Exception_RuntimeException_Base) {
//            case Exception_ArrayIndexOutOfBoundsException:
//                Exception_RuntimeException_Table[i].Tag = i + Exception_RuntimeException_Base;
//                Exception_RuntimeException_Table[i].Name = "ArrayIndexOutOfBoundsException";
//                Exception_RuntimeException_Table[i].Message = "Array Index Out Of Bounds";
//                Exception_RuntimeException_Table[i].Handler = &Exception_RuntimeException_DefaultHandler;
//                break;
//            case Exception_IllegalArgumentException:
//                Exception_RuntimeException_Table[i].Tag = i + Exception_RuntimeException_Base;
//                Exception_RuntimeException_Table[i].Name = "IllegalArgumentException";
//                Exception_RuntimeException_Table[i].Message = "Illegal Argument";
//                Exception_RuntimeException_Table[i].Handler = &Exception_RuntimeException_DefaultHandler;
//                break;
//            case Exception_NullPointerException:
//                Exception_RuntimeException_Table[i].Tag = i + Exception_RuntimeException_Base;
//                Exception_RuntimeException_Table[i].Name = "NullPointerException";
//                Exception_RuntimeException_Table[i].Message = "Null Pointer";
//                Exception_RuntimeException_Table[i].Handler = &Exception_RuntimeException_DefaultHandler;
//                break;
//            default:
//                Exception_RuntimeException_Table[i].Tag = i + Exception_RuntimeException_Base;
//                Exception_RuntimeException_Table[i].Name = "RuntimeException";
//                Exception_RuntimeException_Table[i].Message = "Runtime Exception";
//                Exception_RuntimeException_Table[i].Handler = &Exception_RuntimeException_DefaultHandler;
//        }
//    }
//
//    return SUCCESS;
//}

Status Exception_RuntimeException_DefaultHandler(const UT exception){
    if((exception < Exception_RuntimeException_Base) || (exception > (Exception_RuntimeException_Base + Exception_RuntimeException_Total))) {
        return FAILURE;
    }
    //空
    return SUCCESS;
}

