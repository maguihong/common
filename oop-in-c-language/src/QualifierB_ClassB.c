/*
基础头文件包含区域
*/


/*
其他类头文件包含区域
*/


/*
本类头文件包含区域
*/
#define BB QualifierB_ClassB
#define Alias_QualifierB_ClassB BB_
#include"QualifierB_ClassB.h"

CONSTANT BB FullName(Initializer) = FullName(InitializerBlock);



AA* FullName(CastTo_QualifierA_ClassA)(BB *object){
    return &(object->mBase1);
}

S3 FullName(Method1)(V *CONSTANT self, S3 s){
    BB *b = (BB *)self;
    b->mField1 += s;
    return b->mField1;
}

F1 FullName(Method2)(V *CONSTANT self, F1 f){
    BB *b = (BB *)self;
    b->mField2 += f;
    return b->mField2;
}

S3 FullName(Method3)(V *CONSTANT self, S3 s){
    BB *b = (BB *)self;
    b->mField1 += s;
    return b->mField1;
}

