#ifndef Header_Mashon_Base
#define Header_Mashon_Base

//有符号整数类型
typedef signed char         S1;    // -128 ~ 127
typedef signed short int    S2;    // -32768 ~ 32767
typedef signed int          S3;    // -2147483648 ~ 2147483647
typedef signed long long    S4;    // -9.2233720368548E18 ~ 9.2233720368548E18

//无符号整数类型
typedef unsigned char       U1;    // 0 ~ 256 // unsigned类型赋值给int时不会进行符号扩展
typedef unsigned short int  U2;    // 0 ~ 65535
typedef unsigned int        U3;    // 0 ~ 4294967296
typedef unsigned long long  U4;    // 0 ~ 1.844674407371E19

//浮点数类型
typedef float               F1;     // -3.4E38 ~ 3.4E38
typedef double              F2;     // -1.7E308 ~ 1.7E308

//空类型
typedef void                V;      // void

//字节类型
typedef char                B;      // byte

//字符类型
typedef char                C;      // char
//#define Mashon_Base_CharacterSize   2
//typedef char                C[Mashon_Base_CharacterSize];

//布尔类型
typedef enum Boolean{
    TRUE = 1,
    FALSE = 0
}Boolean;

//状态类型
typedef enum Status{
    SUCCESS = 1,
    FAILURE = 0
}Status;

//类型限定符
#define CONSTANT            const                   // 变量在程序执行期间不可写
#define VOLATILE            volatile                // 变量的值可能以程序未明确指定的方式被改变
#define RESTRICT            restrict                // 修饰的指针是唯一可以访问它所指向的对象

//存储类型福
#define AUTO                auto
#define REGISTER            register
#define STATIC              static
#define EXTERN              extern

//有符号整数可取的最大类型
typedef S4                  SX;
//无符号整数可取的最大类型
typedef U4                  UX;
//浮点数可取的最大类型
typedef F2                  FX;

//有符号整数类型随平台迁移而保持兼容
typedef S3                  ST;
//无符号整数类型随平台迁移而保持兼容
typedef U3                  UT;
//浮点数类型随平台迁移而保持兼容
typedef F1                  FT;

//无符号整数类型最大值
#define U8_Max              255U                    // 256 - 1
#define U16_Max             65535U                  // 64K - 1
#define U32_Max             4294967295UL            // 4G - 1
#define U64_Max             18446744073709551615ULL // 16E - 1



#endif // Header_Mashon_Base
