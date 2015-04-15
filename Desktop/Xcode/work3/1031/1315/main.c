//
//  main.c
//  1315
//
//  Created by 刘家琪 on 15/4/14.
//  Copyright (c) 2015年 家琪. All rights reserved.
//

#include <stdio.h>
int main()
{
    int max, index_i, index_j;
    int A[100][100];
    int F[101][101];
    int P[101];
    int Q[101];
    int N;
    scanf("%d", &N);
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            scanf("%d", &A[i][j]);
    for(int i=1; i<N+1; i++) {
        F[i][0] = 0;
        F[i][1] = A[i-1][0];
    }
    for(int i=1; i<N+1; i++) {
        for(int j=2; j<N+1; j++)
        {
            F[i][j] = F[i][j-1] + A[i-1][j-1];
        }
    }
    max = 0;
    for(int i = 1; i < N+1; i++)
    {
        for(int j = i+1; j < N+1; j++)
        {
            P[1] = F[1][j]-F[1][i-1];
            Q[1] = P[1];
            for(int k=2; k<N+1; k++)
            {
                P[k] = P[k-1]>0?(P[k-1]+F[k][j]-F[k][i-1]):(F[k][j]-F[k][i-1]);
                Q[k] = Q[k-1]>P[k]?Q[k-1]:P[k];
            }
            if(Q[N] > max)
            {
                max = Q[N];
                index_i = i;
                index_j = j;
            }
        }
    }
    printf("%d\n",max);
    return 0;
}