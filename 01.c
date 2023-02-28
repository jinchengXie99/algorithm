/*************************************************************************
	> File Name: 01.c
	> Author: Jincheng Xie
	> Mail: chengdiy@foxmail.com
	> Created Time: Mon Aug  1 19:16:15 2022
 ************************************************************************/


#include<stdio.h>
int main()
{
    int a[5]={1,2,3,4,5};

    printf(" sizeof  数组名=%d\n", sizeof(a));

    printf("sizeof *数组名=%d\n", sizeof(*a));
}
