#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;
/*
Strassen矩阵乘积分治算法
7次对于n/2阶矩阵乘积的递归调用和18次n/2阶矩阵的加减运算

*/

int N;

//二阶矩阵相乘
void Matrix_Multiply(int A[][N], int B[][N], int C[][N]) 
{ 
     for(int i = 0; i < 2; i++) {  
        for(int j = 0; j < 2; j++) {  
           C[i][j] = 0;        
           for(int t = 0; t < 2; t++) {  
              C[i][j] = C[i][j] + A[i][t] * B[t][j];          
           }    
        }          
     }  
}  

//矩阵加法：
void add(int n, int A[][N], int B[][N], int R[][N])
{ 
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            R[i][j] = A[i][j] + B[i][j];
}

//矩阵减法：
void sub(int n, int A[][N], int B[][N], int R[][N])
{ 
    int i,j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            R[i][j] = A[i][j] - B[i][j];
}
void strassen(int n, int A[][N], int B[][N], int C[][N])
{
    int i, j;
    int A11[N][N], A12[N][N], A21[N][N], A22[N][N];
    int B11[N][N], B12[N][N], B21[N][N], B22[N][N];
    int C11[N][N], C12[N][N], C21[N][N], C22[N][N];
    int AA[N][N], BB[N][N];
    int M1[N][N], M2[N][N], M3[N][N], M4[N][N], M5[N][N], M6[N][N], M7[N][N];
    if(n == 2) {
        Matrix_Multiply(A, B, C);
    } else {
        for(i = 0; i < n / 2; i++) {
            for(j = 0; j < n / 2; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + n / 2];
                A21[i][j] = A[i + n / 2][j];
                A22[i][j] = A[i + n / 2][j + n / 2];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + n / 2];
                B21[i][j] = B[i + n /2][j];
                B22[i][j] = B[i + n /2][j + n / 2];
            }
        }

        sub(n / 2, B12, B22, BB);
        strassen(n / 2, A11, BB, M1);

        add(n / 2, A11, A12, AA);
        strassen(n / 2, AA, B22, M2);

        add(n / 2, A21, A22, AA);
        strassen(n / 2, AA, B11, M3);

        sub(n / 2, B21, B11, BB);
        strassen(n / 2, A22, BB, M4);

        add(n / 2, A11, A22, AA);
        add(n / 2, B11, B22, BB);
        strassen(n / 2, AA, BB, M5);

        sub(n / 2, A12, A22, AA);
        add(n / 2, B21, B22, BB);
        strassen(n / 2, AA, BB, M6);

        sub(n / 2, A11, A21, AA);
        add(n / 2, B11, B12, BB);
        strassen(n / 2, AA, BB, M7);

        //C11 = M5 + M4 - M2 + M6
        add(n / 2, M5, M4, AA);
        sub(n / 2, M6, M2, BB);
        add(n / 2, AA, BB, C11);

        //C12 = M1 + M2
        add(n / 2, M1, M2, C12);

        //C21 = M3 + M4
        add(n / 2, M3, M4, C21);

        //C22 = M5 + M1 - M3 - M7
        sub(n / 2, M5, M3, AA);
        sub(n / 2, M1, M7, BB);
        add(n / 2, AA, BB, C22);

         for(i = 0; i < n / 2; i++) {  
           for(j = 0; j < n / 2; j++) {  
              C[i][j] = C11[i][j];  
              C[i][j + n / 2] = C12[i][j];  
              C[i + n / 2][j] = C21[i][j];  
              C[i + n / 2][j + n / 2] = C22[i][j];          
           }          
        } 
    }
}

int main(void)
{
	N=4;
    int A[N][N], B[N][N], C[N][N];
    printf("input A: \n");
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);
    printf("input B: \n");
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &B[i][j]);
    strassen(N, A, B, C);
    printf("C:\n");
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
            if(j > 0 && j % 3 == 0)
                printf("\n");
        }
    return 0;
}
