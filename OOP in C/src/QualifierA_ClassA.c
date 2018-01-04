/*
基础头文件包含区域
*/


/*
其他类头文件包含区域
*/


/*
本类头文件包含区域
*/
#define AA QualifierA_ClassA
#define Alias_QualifierA_ClassA AA_
#include"QualifierA_ClassA.h"


CONSTANT AA FullName(Initializer) = FullName(InitializerBlock);



S3 FullName(Method1)(V *CONSTANT self, S3 s){
    AA *a = (AA *)self;
    a->mField1 += s;
    return a->mField1;
}

F1 FullName(Method2)(V *CONSTANT self, F1 f){
    AA *a = (AA *)self;
    a->mField2 += f;
    return a->mField2;
}



























//撤销宏定义（闭合作用域）
#undef ClassA
#undef ClassA_PrivateMembers
#undef Method0
#undef Method1
