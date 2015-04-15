//
//  main.c
//  1316
//
//  Created by 刘家琪 on 15/4/14.
//  Copyright (c) 2015年 家琪. All rights reserved.
//

#include <stdio.h>
float s = 0;
typedef struct
{
    int w;
    int v;
    double ev;
}data;
data wv[100000];
int main()
{
    void Sort(int N);
    int In(int M, int f);
    int i,j;
    int N,M;
    scanf("%d %d", &M, &N);
    for(i = 1; i <= N; i++)
    {
        scanf("%d %d", &wv[i].w, &wv[i].v);
        wv[i].ev = (double)wv[i].v/wv[i].w;
    }
    Sort(N);
    j = 1;
    do
    {
        //for(j = 1; j <= N ; j++)
        //{
        if(M != 0 && wv[j].w != 0)
            M = In(M, j);
        j++;
        //}
    }while(wv[N].w != 0 && M != 0);
    printf("%.6f\n", s);
    return 0;
}

void Sort(int N)
{
    int i,j;
    data k;
    for(i = 2; i <= N; i++)
    {
        j = i;
        while(j > 1 && wv[j].ev > wv[j-1].ev)
        {
            k = wv[j];
            wv[j] = wv[j-1];
            wv[j-1] = k;
            j--;
        }
    }
}

int In(int M, int f)
{
    if(M - wv[f].w >= 0)
    {
        M = M - wv[f].w;
        wv[f].w = 0;
        s = s + wv[f].v;
        return M;
    }
    else
    {
        wv[f].w = wv[f].w - M;
        s = s + M * wv[f].ev;
        M = 0;
        return M;
    }
}
