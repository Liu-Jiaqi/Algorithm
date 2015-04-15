//
//  main.c
//  Cpk
//
//  Created by 刘家琪 on 15/4/12.
//  Copyright (c) 2015年 家琪. All rights reserved.
//

#include<stdio.h>
#include<string.h>
struct DataType
{
    char name[16];
    int starttime1;   //hours
    int starttime2;   //minuts
    float starttime;
    int endtime1;    //hours
    int endtime2;    //minuts
    float endtime;
};

struct DataType Girl[1001];
struct DataType M[1001];

int main()
{
    int Scan();
    void QSort(int N);
    int Select();
    void Prin();
    int N, num;
    N = Scan();
    QSort(N);
    num = Select(N);
    Prin(num);
    return 0;
}

int Scan()
{
    int N,i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++)
    {
        scanf("%s", Girl[i].name);
        scanf("%d:%d", &Girl[i].starttime1, &Girl[i].starttime2);
        Girl[i].starttime = Girl[i].starttime1 + 0.01 * Girl[i].starttime2;
        scanf("%d:%d", &Girl[i].endtime1, &Girl[i].endtime2);
        Girl[i].endtime = Girl[i].endtime1 + 0.01 * Girl[i].endtime2;
    }
    return N;
}

void QSort(int N)
{
    void Sort(int s, int t);
    Sort(1, N);
}

void Sort(int s, int t)
{
    int Partition(int low, int high);
    int pivotloc;
    if(s < t-1)
    {
        pivotloc = Partition(s,t);
        Sort(s, pivotloc - 1);
        Sort(pivotloc + 1, t);
    }
}

int Partition(int low, int high)
{
    int pivotkey;
    struct DataType k;
    Girl[0] = Girl[low];
    pivotkey = Girl[low].endtime;
    while(low < high)
    {
        while(low < high && Girl[high].endtime >= pivotkey)
            --high;
        k = Girl[low];
        Girl[low] = Girl[high];
        Girl[high] = k;
        while(low < high && Girl[low].endtime <= pivotkey)
            ++low;
        k = Girl[low];
        Girl[low] = Girl[high];
        Girl[high] = k;
    }
    Girl[low] = Girl[0];
    return low;
}

int Select(int N)
{
    int j = 1, i =1;
    M[1] = Girl[1];
    for(j = 2; j <= N; j++)
    {
        if(Girl[j].starttime >= M[i].endtime)
        {
            M[++i] = Girl[j];
        }
    }
    return i;
}

void Prin(int num)
{
    int i;
    for(i = 1; i <= num; i++)
        printf("%s ", M[i].name);
}


