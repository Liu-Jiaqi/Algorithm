//
//  main.c
//  Perm
//
//  Created by 刘家琪 on 15/3/22.
//  Copyright (c) 2015年 家琪. All rights reserved.
//

#include <stdio.h>

int N = 4;

int P[10];
int main()
{
    void Perm2(int M);
    int i;
    //对数组初始化
    for(i = 1; i <= N; i++)
    {
        P[i] = 0;
    }
    //调用排序函数
    Perm2(1);
    return 0;
}

void Perm2(int M)
{
    void Print(int P[]);
    int i;
    if(M == N+1)
        Print(P);
    else
    {
        for(i = 1; i <= N; i++)
        {
            if(P[i] == 0)
            {
                P[i] = M;
                Perm2(M+1);
                P[i] = 0;
            }
        }
    }
}


void Print(int P[])
{
    int i;
    for(i = 1; i <= N;i++)
        printf("%d\t",P[i]);
    printf("\n");
    
}







