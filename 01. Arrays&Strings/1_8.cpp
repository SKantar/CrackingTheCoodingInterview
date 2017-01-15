/**
*   Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
*   column are set to 0.
**/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 256
using namespace std;

/***************************************************
*  Brute force solution
*  Time Complexity: O(2 * n * m + n^2 * m + n * m ^ 2)
*  O(max(n, m) ^ 3) = O(n ^ 3)  'n' = max(n, m)
*  Memory Compleity: O(nm)
****************************************************
void update(int mat[][MAXN], int n, int m){
    int mat1[MAXN][MAXN];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            mat1[i][j] = mat[i][j];


    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 0){
                for(int k = -1; k < n; k++)
                    mat1[k][j] = 0;
                for(int k = 0; k < m; k++)
                    mat1[i][k] = 0;
            }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            mat[i][j] = mat1[i][j];
}
***************************************************/

/***************************************************
*  Time Complexity: O(n + m + nm + nm)
*                   O(n ^ 2) 'n' - max(n, m)
*  Memory Compleity: O(n + m) => O(n)
***************************************************/

void update(int mat[][MAXN], int n, int m){
    bool row[MAXN], column[MAXN];
    memset(row, false, MAXN * sizeof(bool));
    memset(column, false, MAXN * sizeof(bool));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 0){
                row[i] = true;
                column[j] = true;
            }


    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(row[i] || column[j])
                mat[i][j] = 0;

}

int main(){
    freopen("input.txt", "r", stdin);
    int n, m, mat[MAXN][MAXN];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", mat[i] + j);

    update(mat, n, m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }



}
