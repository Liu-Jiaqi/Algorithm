//
//  main.c
//  1028
//
//  Created by 刘家琪 on 15/4/14.
//  Copyright (c) 2015年 家琪. All rights reserved.
//

#include <stdio.h>
int nu[1000];
int s = 1;
typedef struct
{
    int mi; //size
    int vi; //degree
    int key;
    int n;
    double ev;
}data;
data mv[1000];
int main()
{
    void Sort(int N);
    int In(int M, int f);
    int i,j,k;
    int N,M;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++)
        scanf("%d", &mv[i].mi);
    for(i = 1; i <= N; i++)
        scanf("%d", &mv[i].vi);
    for(i = 1; i <= N; i++)
    {
        mv[i].ev = (double)mv[i].vi/mv[i].mi;
        mv[i].key = i;
        mv[i].n = 1;
    }
    Sort(N);
    do
    {
        k = 0;
        for(j = 1; j <= N ; j++)
        {
            if(M >= mv[j].mi && mv[j].n == 1)
            {
                M = In(M, j);
                k = 1;
            }
        }
    }while(k == 1 && j <= N);
    for(i = 1; i < s; i++)
        printf("%d\t", nu[i]);
    printf("\n");
    return 0;
}

void Sort(int N)
{
    int i,j;
    data k;
    for(i = 2; i <= N; i++)
    {
        j = i;
        while(j > 1 && mv[j].ev > mv[j-1].ev)
        {
            k = mv[j];
            mv[j] = mv[j-1];
            mv[j-1] = k;
            j--;
        }
    }
}

int In(int M, int f)
{
    M = M - mv[f].mi;
    mv[f].n = 0;
    nu[s] = mv[f].key;
    s++;
    return M;
}
