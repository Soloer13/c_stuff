#include "stdio.h"

void main()
{
    int x = 5, y = 9;

    int* pX = &x; //Pointer

    int** ppX = &pX; //Pointer to Pointer

    // x=5  y=9
    printf("x = %d, y = %d\r\n", x, y);

    **ppX = 7; //point to "x"
    // x=7  y=9
    printf("x = %d, y = %d\r\n", x, y);

    *ppX = &y; // makes "PX" point to "y"
    *pX = 11;  // change "y"'s value to "11"

    printf("x = %d, y = %d\r\n", x, y);
}
