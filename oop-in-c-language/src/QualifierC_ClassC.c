/*
基础头文件包含区域
*/


/*
其他类头文件包含区域
*/


/*
本类头文件包含区域
*/
#define CC QualifierC_ClassC
#define Alias_QualifierC_ClassC CC_
#include"QualifierC_ClassC.h"

CONSTANT CC FullName(Initializer) = FullName(InitializerBlock);



AA* FullName(CastTo_QualifierA_ClassA)(CC *object){
    return ClassB_CastTo(ClassC_CastTo(object, BB), AA);
}

BB* FullName(CastTo_QualifierB_ClassB)(CC *object){
    return &(object->mBase1);
}

S3 FullName(Method1)(V *CONSTANT self, S3 s){
    CC *c = (CC *)self;
    c->mField1 += s;
    return c->mField1;
}

F1 FullName(Method2)(V *CONSTANT self, F1 f){
    CC *c = (CC *)self;
    c->mField2 += f;
    return c->mField2;
}
