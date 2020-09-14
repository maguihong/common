#ifndef Header_QualifierC_ClassC
#define Header_QualifierC_ClassC

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

#define BB QualifierB_ClassB
#define Alias_QualifierB_ClassB BB_
#include"QualifierB_ClassB.h"








#ifndef Alias_QualifierC_ClassC
#define Alias_QualifierC_ClassC ClassC_
#endif // Alias_QualifierC_ClassC

#ifdef FullName
#undef FullName
#endif // FullName
#define FullName(name)  QualifierC_ClassC_##name

#ifdef ShortName
#undef ShortName
#endif // ShortName
#define ShortName(name) _ShortName(Alias_QualifierC_ClassC, name)

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

#ifdef ClassC
#undef ClassC
#endif // ClassC
#define ClassC QualifierC_ClassC

#ifdef Class_ClassC
#undef Class_ClassC
#endif // Class_ClassC
#define Class_ClassC QualifierC_ClassC

typedef struct {
    BB Member(Base1);

    S3 Member(Field1);
    F1 Member(Field2);

    S3 (*Member(Method1))(V *CONSTANT self, S3 s);
    F1 (*Member(Method2))(V *CONSTANT self, F1 f);

} QualifierC_ClassC;



#define ClassC_CastTo(object, class)            QualifierC_ClassC_CastTo(object, class)
#define QualifierC_ClassC_CastTo(object, class) QualifierC_ClassC_CastTo_##class(object)
AA* FullName(CastTo_QualifierA_ClassA)(Class_ClassC *object);
BB* FullName(CastTo_QualifierB_ClassB)(Class_ClassC *object);


#ifdef Method_Method1
#undef Method_Method1
#endif // Method_Method1
#define Method_Method1 QualifierC_ClassC_Method1
S3 FullName(Method1)(V *CONSTANT self, S3 s);
STATIC S3 ShortName(Method1)(Class_ClassC *CONSTANT self, S3 s){
    return self->mMethod1(self, s);
}

#ifdef Method_Method2
#undef Method_Method2
#endif // Method_Method2
#define Method_Method2 QualifierC_ClassC_Method2
F1 FullName(Method2)(V *CONSTANT self, F1 f);
STATIC F1 ShortName(Method2)(Class_ClassC *CONSTANT self, F1 f){
    return self->mMethod2(self, f);
}



#define QualifierC_ClassC_InitializerBlock                  \
{                                                           \
    .Member(Base1) = QualifierB_ClassB_InitializerBlock,    \
                                                            \
    .Member(Field1) = 3,                                    \
    .Member(Field2) = 3.0,                                  \
                                                            \
    .Member(Method1) = &Method_Method1,                     \
    .Member(Method2) = &Method_Method2                      \
}
extern CONSTANT Class_ClassC FullName(Initializer);



#undef Alias_QualifierC_ClassC

#endif // Header_QualifierC_ClassC
