#include "stdio.h"

void main(){
    int array[] = {9,8,7,6,5,4,3,2,1};

    int i, j, temp;

    for(i = 0 ; i < 9 ; i++){
        for(j = 0 ; j < 9 ; j++){
            // if J is smaller swap
            if(array[i] < array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for(i=0;i<9;i++)
        printf("%d\r\n", array[i]);

}
