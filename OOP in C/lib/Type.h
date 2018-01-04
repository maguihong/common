#ifndef __TYPE_H
#define __TYPE_H

#include<stdarg.h> // va_list

#define Const               const

/*********************************常用类型->*********************************/
typedef signed char         S8; // -128 ~ 127
typedef signed short int    S16; // -32768 ~ 32767
typedef signed int          S32; // -2147483648 ~ 2147483647
typedef signed long long    S64; // -9.2233720368548E18 ~ 9.2233720368548E18

typedef unsigned char       U8; // 0 ~ 256 // unsigned类型赋值给int时不会进行符号扩展
typedef unsigned short int  U16; // 0 ~ 65535
typedef unsigned int        U32; // 0 ~ 4294967296
typedef unsigned long long  U64; // 0 ~ 1.844674407371E19

typedef float               F32; // -3.4E38 ~ 3.4E38
typedef double              F64; // -1.7E308 ~ 1.7E308

typedef void                V;
/*********************************<-常用类型*********************************/



/**********************各类型最大值->*********************/
//C语言整型常量默认为signed int,转换后缀为U、L
#define Max_U8              255U                    //256
#define Max_U16             65535U                  //64K
#define Max_U32             4294967295UL            //4G
#define Max_U64             18446744073709551615ULL //16E
/**********************<-各类型最大值*********************/



typedef S8                  Status;
#define SUCCESS             1
#define FAILURE             0

typedef S8                  Boolean;
#define TRUE                1
#define FALSE               0



/*******************字符串或字节流类型->******************/
typedef char                C; //字符型
typedef char                B; //字节型

typedef struct C8{
    U8 Size;
    C* Buffer;
}C8;
typedef struct C16{
    U16 Size;
    C* Buffer;
}C16;
typedef struct C32{
    U32 Size;
    C* Buffer;
}C32;
typedef struct C64{
    U64 Size;
    C* Buffer;
}C64;
Status C8_Init(C8 *c8, const C* string, U8 size);
Status C16_Init(C16 *c16, const C* string, U16 size);
Status C32_Init(C32 *c32, const C* string, U32 size);
Status C64_Init(C64 *c64, const C* string, U64 size);
Status C8_Set(C8 *c8, const C* string);
Status C16_Set(C16 *c16, const C* string);
Status C32_Set(C32 *c32, const C* string);
Status C64_Set(C64 *c64, const C* string);
Status C8_Cat(C8 *c8, const C* string);
Status C16_Cat(C16 *c16, const C* string);
Status C32_Cat(C32 *c32, const C* string);
Status C64_Cat(C64 *c64, const C* string);
Status C8_Del(C8 *c8);
Status C16_Del(C16 *c16);
Status C32_Del(C32 *c32);
Status C64_Del(C64 *c64);

typedef struct B8{
    U8 Size;
    U8 Length;
    B* Buffer;
}B8;
typedef struct B16{
    U16 Size;
    U16 Length;
    B* Buffer;
}B16;
typedef struct B32{
    U32 Size;
    U32 Length;
    B* Buffer;
}B32;
typedef struct B64{
    U64 Size;
    U64 Length;
    B* Buffer;
}B64;
Status B8_Init(B8 *b8, const B* bytes, U8 size);
Status B16_Init(B16 *b16, const B* bytes, U16 size);
Status B32_Init(B32 *b32, const B* bytes, U32 size);
Status B64_Init(B64 *b64, const B* bytes, U64 size);
Status B8_Set(B8 *b8, const B* bytes, U8 length);
Status B16_Set(B16 *b16, const B* bytes, U16 length);
Status B32_Set(B32 *b32, const B* bytes, U32 length);
Status B64_Set(B64 *b64, const B* bytes, U64 length);
Status B8_Del(B8 *b8);
Status B16_Del(B16 *b16);
Status B32_Del(B32 *b32);
Status B64_Del(B64 *b64);
/*******************<-字符串或字节流类型******************/



/***************可支持的最大范围类型->****************/
#define Max_UX              Max_U64

typedef S64                 SX; // 用于对象类型升级转换
typedef U64                 UX;
typedef F64                 FX;
typedef C64                 CX;
typedef B64                 BX;
/***************<-可支持的最大范围类型****************/



/*****************当前环境兼容类型->******************/
#define Max_UT              Max_U32

typedef S32                 ST;
typedef U32                 UT;
typedef F32                 FT;
typedef C32                 CT;
typedef B32                 BT;

Status CT_Init(CT *ct, const C* string, UT size);
Status CT_Set(CT *ct, const C* string);
Status CT_Cat(CT *ct, const C* string);
Status CT_Del(CT *ct);
Status BT_Init(BT *bt, const B* bytes, UT size);
Status BT_Set(BT *bt, const B* bytes, UT length);
Status BT_Del(BT *bt);
/*****************<-当前环境兼容类型******************/



/***************时间类型->***************/
typedef C                   Time[20];
Status Now(Time t);
/***************<-时间类型***************/



/****************函数指针类型->*****************/
typedef Status (*Function)(va_list args);
/****************<-函数指针类型*****************/



#endif // __TYPE_H
