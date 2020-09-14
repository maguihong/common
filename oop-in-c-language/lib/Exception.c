#include"Exception.h"
#include<stddef.h> // NULL
#include<string.h> // strxxx strerror
#include<stdio.h> // vsnprintf

CT Exception_Buffer;

Status Exception_Init(){

    CT_Init(&Exception_Buffer, NULL, Exception_BufferSize);

    //Exception_NonException_Init();
    //Exception_RuntimeException_Init();
    //Exception_IOException_Init();
    //Exception_NetworkException_Init();

    return SUCCESS;
}

Status Exception_Print(Const UT exception,Const S32 error, CT *buffer, Const C *format, ...){

    UT size = 0;
    if(buffer != NULL && buffer->Size > 0 && buffer->Buffer != NULL) {
        size = buffer->Size;
        CT_Set(buffer, NULL);
    }

    UT length = 0;
    ST writable = size - length;
    va_list args;
    Time time;
    if(writable > 0){
        Now(time);

        if(exception >= Exception_NonException_Base && exception < (Exception_NonException_Base + Exception_NonException_Total)){
            length = strlen(buffer->Buffer);
            writable = size - length;
            snprintf(buffer->Buffer + length, writable > 1 ? writable : 1, "%s\tOutput: %s ", time, Exception_GetName(exception));

            va_start(args, format);
            length = strlen(buffer->Buffer);
            writable = size - length;
            vsnprintf(buffer->Buffer + length, writable > 1 ? writable : 1, format, args);
            va_end(args);
        }else{
            length = strlen(buffer->Buffer);
            writable = size - length;
            snprintf(buffer->Buffer + length, writable > 1 ? writable : 1, "%s\tWarning: ", time);

            va_start(args, format);
            length = strlen(buffer->Buffer);
            writable = size - length;
            vsnprintf(buffer->Buffer + length, writable > 1 ? writable : 1, format, args);
            va_end(args);

            length = strlen(buffer->Buffer);
            writable = size - length;
            snprintf(buffer->Buffer + length, writable > 1 ? writable : 1, "%s\tException: %d %s [%s]\n", time, exception, Exception_GetName(exception), Exception_GetMessage(exception));

            length = strlen(buffer->Buffer);
            writable = size - length;
            snprintf(buffer->Buffer + length, writable > 1 ? writable : 1, "%s\tError: %d %s\n", time, error, strerror(error));
        }

        fflush(stdout); // in case stdout and stderr are the same
        fputs(buffer->Buffer, stderr);
        fflush(NULL); // flushes all stdio buffer streams

        return SUCCESS;
    }else{
        return FAILURE;
    }
}

const C* Exception_GetMessage(Const UT exception){

    if(exception >= Exception_NonException_Base && exception < (Exception_NonException_Base + Exception_NonException_Total)){
        return Exception_NonException_Table[exception - Exception_NonException_Base].Message;
    }

    if(exception >= Exception_RuntimeException_Base && exception < (Exception_RuntimeException_Base + Exception_RuntimeException_Total)){
        return Exception_RuntimeException_Table[exception - Exception_RuntimeException_Base].Message;
    }

    if(exception >= Exception_IOException_Base && exception < (Exception_IOException_Base + Exception_IOException_Total)){
        return Exception_IOException_Table[exception - Exception_IOException_Base].Message;
    }

    if(exception >= Exception_NetworkException_Base && exception < (Exception_NetworkException_Base + Exception_NetworkException_Total)){
        return Exception_NetworkException_Table[exception - Exception_NetworkException_Base].Message;
    }

    return NULL;
}

const C* Exception_GetName(Const UT exception){

    if(exception >= Exception_NonException_Base && exception < (Exception_NonException_Base + Exception_NonException_Total)){
        return Exception_NonException_Table[exception - Exception_NonException_Base].Name;
    }

    if(exception >= Exception_RuntimeException_Base && exception < (Exception_RuntimeException_Base + Exception_RuntimeException_Total)){
        return Exception_RuntimeException_Table[exception - Exception_RuntimeException_Base].Name;
    }

    if(exception >= Exception_IOException_Base && exception < (Exception_IOException_Base + Exception_IOException_Total)){
        return Exception_IOException_Table[exception - Exception_IOException_Base].Name;
    }

    if(exception >= Exception_NetworkException_Base && exception < (Exception_NetworkException_Base + Exception_NetworkException_Total)){
        return Exception_NetworkException_Table[exception - Exception_NetworkException_Base].Name;
    }

    return NULL;
}

Status Exception_Catch(Const UT exception, Function function, ...){

    if(function != NULL){
        va_list args;
        va_start(args, function);
        (*function)(args);
        va_end(args);
    }

    if(exception >= Exception_NonException_Base && exception < (Exception_NonException_Base + Exception_NonException_Total)){
        return Exception_NonException_Table[exception - Exception_NonException_Base].Handler(exception);
    }

    if(exception >= Exception_RuntimeException_Base && exception < (Exception_RuntimeException_Base + Exception_RuntimeException_Total)){
        Exception_RuntimeException_Table[exception - Exception_RuntimeException_Base].Handler(exception);
        return SUCCESS;
    }

    if(exception >= Exception_IOException_Base && exception < (Exception_IOException_Base + Exception_IOException_Total)){
        Exception_IOException_Table[exception - Exception_IOException_Base].Handler(exception);
        return SUCCESS;
    }

    if(exception >= Exception_NetworkException_Base && exception < (Exception_NetworkException_Base + Exception_NetworkException_Total)){
        Exception_NetworkException_Table[exception - Exception_NetworkException_Base].Handler(exception);
        return SUCCESS;
    }

    return FAILURE;
}


