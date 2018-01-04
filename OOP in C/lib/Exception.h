#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#include"Type.h"
#include"ExceptionConfig.h"
#include"ExceptionNon.h"
#include"ExceptionRuntime.h"
#include"ExceptionIO.h"
#include"ExceptionNetwork.h"
#include<stdarg.h> // va_list va_start va_end va_arg
#include<errno.h> // errno

Status Exception_Init();
Status Exception_Print(Const UT exception, Const S32 error, CT *buffer, Const C *format, ...);
Status Exception_Catch(Const UT exception, Function function, ...);
Const C* Exception_GetMessage(Const UT exception);
Const C* Exception_GetName(Const UT exception);

extern CT Exception_Buffer;

#endif // __EXCEPTION_H

/*
新增Exception类时：
    + ExceptionConfig.h
        #define Exception_XXX_Base              ???
    + ExceptionXXX.h
        #define Exception_XXX_Total             ?                           //新增异常时
        #define Exception_XXX                   Exception_XXX_Base
        #define Exception_xxx                   (Exception_XXX_Base + ?)    //新增异常时
        extern Exception Exception_XXX_Table[Exception_XXX_Total];
        Status Exception_XXX_Init();
    + ExceptionXXX.c
        Exception Exception_XXX_Table[Exception_XXX_Total];                 //新增异常时
        Status Exception_XXX_DefaultHandler(const UT exception){}
    + Exception.h
        #include"ExceptionXXX.h"
    + Exception.c
        Status Exception_Catch(const UT exception){}
        const C* Exception_GetMessage(const UT exception){}
        const C* Exception_GetName(const UT exception){}
*/



/*
int printf(const char *format, ...); //输出到标准输出
int fprintf(FILE *stream, const char *format, ...); //输出到文件
int sprintf(char *str, const char *format, ...); //输出到字符串str中
int snprintf(char *str, size_t size, const char *format, ...); //按size大小输出到字符串str中

以下函数功能与上面的一一对应相同，只是在函数调用时，把上面的...对应的一个个变量用va_list调用所替代。在函数调用前ap要通过va_start()宏来动态获取。
#include <stdarg.h>
int vprintf(const char *format, va_list ap);
int vfprintf(FILE *stream, const char *format, va_list ap);
int vsprintf(char *str, const char *format, va_list ap);
int vsnprintf(char *str, size_t size, const char *format, va_list ap);

可变参数列表va_list宏说明：
void va_start(va_list ap, last);
void va_end(va_list ap);
va_start与va_end是成对被调用的，
开始的时候被调用va_start，获得各输出变量地址
结束的时候被调用va_end，释放相应的资源

INTSIZEOF 宏,获取类型占用的空间长度，最小占用长度为int的整数倍：
#define _INTSIZEOF(n) ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

VA_START宏，获取可变参数列表的第一个参数的地址（ap是类型为va_list的指针，v是可变参数最左边的参数）：
#define va_start(ap,v) ( ap = (va_list)&v + _INTSIZEOF(v) )

VA_ARG宏，获取可变参数的当前参数，返回指定类型并将指针指向下一参数（t参数描述了当前参数的类型）：
#define va_arg(ap,t) ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )

VA_END宏，清空va_list可变参数列表：
#define va_end(ap) ( ap = (va_list)0 )
*/
