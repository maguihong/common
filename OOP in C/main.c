#include <stdio.h>
#include <stdlib.h>
#include"Mashon_Base.h"

#define AA QualifierA_ClassA
#define Alias_QualifierA_ClassA AA_
#include"QualifierA_ClassA.h"

#define BB QualifierB_ClassB
#define Alias_QualifierB_ClassB BB_
#include"QualifierB_ClassB.h"

#define CC QualifierC_ClassC
#define Alias_QualifierC_ClassC CC_
#include"QualifierC_ClassC.h"

int main()
{
    AA a = QualifierA_ClassA_Initializer;
    BB b = QualifierB_ClassB_Initializer;
    CC c = QualifierC_ClassC_Initializer;

    printf("%d %f\n", AA_Method1(&a, 0),
                        AA_Method2(&a, 0));
    printf("%d %f %d %f %d\n", AA_Method1(ClassB_CastTo(&b, AA), 0),
                                AA_Method2(ClassB_CastTo(&b, AA), 0),
                                BB_Method1(&b, 0),
                                BB_Method2(&b, 0),
                                BB_Method3(&b, 0));
    printf("%d %f %d %f %d %f %d\n", AA_Method1(ClassC_CastTo(&c, AA), 0),
                                        AA_Method2(ClassC_CastTo(&c, AA), 0),
                                        BB_Method1(ClassC_CastTo(&c, BB), 0),
                                        BB_Method2(ClassC_CastTo(&c, BB), 0),
                                        CC_Method1(&c, 0),
                                        CC_Method2(&c, 0),
                                        BB_Method3(ClassC_CastTo(&c, BB), 0));

    printf("%d %f\n", a.mField1, a.mField2);
    printf("%d %f\n", b.mField1, b.mField2);
    printf("%d %f\n", c.mField1, c.mField2);
    return 0;
}
