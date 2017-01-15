/** 
*	Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
*   bytes, write a method to rotate the image by 90 degrees. Can you do this in place?             
**/

#include <stdio.h>
#include <stdlib.h>
#define MAXN 100

int matrix[MAXN][MAXN], n;

void rotate()
{
    int i, j;
    for(i = 0; i < n / 2; i ++)
    {
        for(j = i; j < n - 1 - i; j ++)
        {
            int tmp = matrix[n - 1 - i - j][i];
            matrix[n - 1 - i - j][i] = matrix[n - 1 - i][n - 1 - i - j];
            matrix[n - 1 - i][n - 1 - i - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = matrix[i][j];
            matrix[i][j] = tmp;
        }
    }
}


int main(){

    int i, j;
    scanf("%d", &n);

    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            scanf("%d", matrix[i] + j);

    rotate();
    rotate();

    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j ++)
        {
           printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
