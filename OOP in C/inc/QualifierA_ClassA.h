#ifndef Header_QualifierA_ClassA
#define Header_QualifierA_ClassA

/*
基础头文件包含区域
*/
#include"Mashon_Base.h"

/*
其他类头文件包含区域
*/








#ifndef Alias_QualifierA_ClassA
#define Alias_QualifierA_ClassA ClassA_
#endif // Alias_QualifierA_ClassA，别名

#ifdef FullName
#undef FullName
#endif // FullName，不在其他宏的值使用该宏函数，ShortName、Member同，防止使用宏后该宏函数意义改变
#define FullName(name)  QualifierA_ClassA_##name

#ifdef ShortName
#undef ShortName
#endif // ShortName
#define ShortName(name) _ShortName(Alias_QualifierA_ClassA, name)

#ifdef _ShortName
#undef _ShortName
#endif // _ShortName
#define _ShortName(alias, name) __ShortName(alias, name)

#ifdef __ShortName
#undef __ShortName
#endif // __ShortName
#define __ShortName(alias, name) alias##name

#ifdef Member
#undef Member
#endif // Member，member可能为宏而阻止其展开
#define Member(member)  m##member

#ifdef Class_ClassA
#undef Class_ClassA
#endif // Class_ClassA，用于本类内作为本类的简化名
#define Class_ClassA QualifierA_ClassA

typedef struct {
    S3 Member(Field1);
    F1 Member(Field2);

    S3 (*Member(Method1))(V *CONSTANT self, S3 s); // 类似this作用
    F1 (*Member(Method2))(V *CONSTANT self, F1 f);

} QualifierA_ClassA; // 类型，不用ClassA，防止其随时更名而无法找到类型



#ifdef Method_Method1
#undef Method_Method1
#endif // Method_Method1
#define Method_Method1 QualifierA_ClassA_Method1 // 重写，不用FullName()，防止其在其它文件时宏被重新定义
S3 FullName(Method1)(V *CONSTANT self, S3 s); // 重写，用于该类及其子类的初始化，若不用进行重写则不必在头文件里声明
STATIC S3 ShortName(Method1)(Class_ClassA *CONSTANT self, S3 s){ // 调用，用简短的方法名进行调用
    return self->mMethod1(self, s);
}

#ifdef Method_Method2
#undef Method_Method2
#endif // Method_Method2
#define Method_Method2 QualifierA_ClassA_Method2
F1 FullName(Method2)(V *CONSTANT self, F1 f);
STATIC F1 ShortName(Method2)(Class_ClassA *CONSTANT self, F1 f){
    return self->mMethod2(self, f);
}




#define QualifierA_ClassA_InitializerBlock  \
{                                           \
    .Member(Field1) = 1,                    \
    .Member(Field2) = 1.0,                  \
                                            \
    .Member(Method1) = &Method_Method1,     \
    .Member(Method2) = &Method_Method2      \
}
EXTERN CONSTANT Class_ClassA FullName(Initializer);



#undef Alias_QualifierA_ClassA

#endif // Header_QualifierA_ClassA
