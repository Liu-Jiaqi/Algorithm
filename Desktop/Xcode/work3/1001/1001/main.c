//
//  main.c
//  算法三
//
//  Created by 刘家琪 on 15/4/14.
//  Copyright (c) 2015年 家琪. All rights reserved.
//

#include <stdio.h>
#define Prince 2.5
int Money[6] = {50, 10, 5, 1, 0.5, 0.1};
int Num[6];
int Put[100000];
int K;

int main()
{
    int Pock(int Re, int i);
    int N,i,Re;
    scanf("%d", &N);
    for(i = 0; i < 6; i++)
    {
        scanf("%d",&Num[i]);
    }
    Re = 100 - N * Prince;
    while(Re >= 0.1)
    {
        if(Re >= Money[0] && Num[0] != 0)
            Re = Pock(Re, 0);
        else if(Re >= Money[1] && Num[1] != 0)
            Re = Pock(Re, 1);
        else if(Re >= Money[2] && Num[2] != 0)
            Re = Pock(Re, 2);
        else if(Re >= Money[3] && Num[3] != 0)
            Re = Pock(Re, 3);
        else if(Re >= Money[4] && Num[4] != 0)
            Re = Pock(Re, 4);
        else if(Re >= Money[5] && Num[5] != 0)
            Re = Pock(Re, 5);
    }
    if(Re == 0)
        printf("%d", K);
    else
        printf("-1");
    return 0;
}

int Pock(int Re, int i)
{
    Re = Re - Money[i];
    Num[i]--;
    K++;
    return Re;
}