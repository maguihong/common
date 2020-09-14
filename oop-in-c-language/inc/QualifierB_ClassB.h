#ifndef Header_QualifierB_ClassB
#define Header_QualifierB_ClassB

/*
基础头文件包含区域
*/
#include"Mashon_Base.h"

/*
其他类头文件包含区域
*/
#define AA QualifierA_ClassA
#define Alias_QualifierA_ClassA AA_
#include"QualifierA_ClassA.h"







#ifndef Alias_QualifierB_ClassB
#define Alias_QualifierB_ClassB ClassB_
#endif // Alias_QualifierB_ClassB

#ifdef FullName
#undef FullName
#endif // FullName
#define FullName(name)  QualifierB_ClassB_##name

#ifdef ShortName
#undef ShortName
#endif // ShortName
#define ShortName(name) _ShortName(Alias_QualifierB_ClassB, name) // ClassB_##name需随ClassB类名改变而改变

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
#endif // Member
#define Member(member)  m##member // member可能为宏而阻止其展开

#ifdef ClassB
#undef ClassB
#endif // ClassB，当改变时，需同时改动ShortName和ClassB_CastTo
#define ClassB QualifierB_ClassB

#ifdef Class_ClassB
#undef Class_ClassB
#endif // Class_ClassB
#define Class_ClassB QualifierB_ClassB

typedef struct {
    AA Member(Base1);

    S3 Member(Field1);
    F1 Member(Field2);

    S3 (*Member(Method1))(V *CONSTANT self, S3 s);
    F1 (*Member(Method2))(V *CONSTANT self, F1 f);
    S3 (*Member(Method3))(V *CONSTANT self, S3 s);

} QualifierB_ClassB;



#define ClassB_CastTo(object, class)            QualifierB_ClassB_CastTo(object, class) // ClassB_CastTo需随ClassB类名改变而改变
#define QualifierB_ClassB_CastTo(object, class) QualifierB_ClassB_CastTo_##class(object)
AA* FullName(CastTo_QualifierA_ClassA)(Class_ClassB *object);



#ifdef Method_Method1
#undef Method_Method1
#endif // Method_Method1
#define Method_Method1 QualifierB_ClassB_Method1
S3 FullName(Method1)(V *CONSTANT self, S3 s);
STATIC S3 ShortName(Method1)(Class_ClassB *CONSTANT self, S3 s){
    return self->mMethod1(self, s);
}

#ifdef Method_Method2
#undef Method_Method2
#endif // Method_Method2
#define Method_Method2 QualifierB_ClassB_Method2
F1 FullName(Method2)(V *CONSTANT self, F1 f);
STATIC F1 ShortName(Method2)(Class_ClassB *CONSTANT self, F1 f){
    return self->mMethod2(self, f);
}

#ifdef Method_Method3
#undef Method_Method3
#endif // Method_Method3
#define Method_Method3 QualifierB_ClassB_Method3
S3 FullName(Method3)(V *CONSTANT self, S3 s);
STATIC S3 ShortName(Method3)(Class_ClassB *CONSTANT self, S3 s){
    return self->mMethod3(self, s);
}



#define QualifierB_ClassB_InitializerBlock                  \
{                                                           \
    .Member(Base1) = QualifierA_ClassA_InitializerBlock,    \
                                                            \
    .Member(Field1) = 2,                                    \
    .Member(Field2) = 2.0,                                  \
                                                            \
    .Member(Method1) = &Method_Method1,                     \
    .Member(Method2) = &Method_Method2,                     \
    .Member(Method3) = &Method_Method3                      \
}
extern CONSTANT Class_ClassB FullName(Initializer);



#undef Alias_QualifierB_ClassB

#endif // Header_QualifierB_ClassB
