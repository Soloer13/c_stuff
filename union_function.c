#include "stdio.h"
#include "string.h"
#include "conio.h"

enum life{false, true};
enum UNUM{INT, FLOAT, DOUBLE};
union variable{
    int i_variable;
    float f_variable;
    double d_variable;
};

union variable add(union variable var1, union variable var2, enum UNUM type);

void main()
{
    union variable var1,var2,result;

    // Int
    var1.i_variable = 1;
    var2.i_variable = 1;
    result = add(var1,var2,INT);
    printf("int %d\n",result.i_variable);


    // Float
    var1.f_variable = 12.32;
    var2.f_variable = 15.68;
    result = add(var1,var2,FLOAT);
    printf("%f\n",result.f_variable);

    //Double
    var1.d_variable = 15.36684;
    var2.d_variable = 13.74426;
    result = add(var1,var2,DOUBLE);
    printf("%lf\n",result.d_variable);

}


union variable add(union variable var1, union variable var2, enum UNUM type){

    union variable result;

    switch(type)
    {
    case INT:
        result.i_variable = var1.i_variable + var2.i_variable;
        break;

    case FLOAT:
        result.f_variable = var1.f_variable + var2.f_variable;
        break;

    case DOUBLE:
        result.d_variable = var1.d_variable + var2.d_variable;
        break;
    }

    return result;
}
