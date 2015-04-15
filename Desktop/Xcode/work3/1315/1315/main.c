//
//  main.c
//  1315
//
//  Created by 刘家琪 on 15/4/14.
//  Copyright (c) 2015年 家琪. All rights reserved.
//

#include<stdio.h>
#include<string.h>
struct Node
{
    char x;
    int k;
    struct Node *lchild;
    struct Node *rchild;
    struct Node *parent;
};

struct Node M[36];
int main()
{
    void Sort1(int n);
    int i, j, N, n;
    char m[100000];
    gets(m);
    N = (int)strlen(m);
    M[1].x = m[0];
    M[1].k++;
    n = 1;
    for(i = 1; i < N; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(M[j].x == m[i])
            {
                M[j].k++;
                break;
            }
        }
        if(j == n+1)
        {
            n++;
            M[n].x = m[i];
            M[n].k++;
        }
    }
    Sort1(n);
    return 0;
}

void Sort1(int n)
{
    int i,j;
    struct Node k;
    for(i = 2; i <= n; i++)
    {
        j = i;
        while(j > 1 && M[j].k > M[j-1].k)
        {
            k = M[j];
            M[j] = M[j-1];
            M[j-1] = k;
            j--;
        }
    }
}

