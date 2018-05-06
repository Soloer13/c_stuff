#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    for(i=0 ; i<10 ; i++){
        printf("%d ",i);
        for(j=1 ; j<10 ; j++){
             if(j>i)
                printf("%d ",j);
        }
        printf("\n");
    }
	
	return 0;

}