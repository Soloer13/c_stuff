#include <stdio.h>
#include <stdlib.h>

int factorial(int x){
    int f=1;

    for(; x>0 ; x--){
        f *=x;
    }
    return f;
}

int main()
{
    printf("%d \n",factorial(5));
    return 0;
}
