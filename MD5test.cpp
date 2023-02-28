/*************************************************************************
	> File Name: MD5test.cpp
	> Author: Jincheng Xie
	> Mail: chengdiy@foxmail.com
	> Created Time: 二  4/19 16:03:18 2022
 ************************************************************************/

#include<iostream>
#include <openssl/md5.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
void getMD5(const char* str,char* result){
	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx,str,strlen(str));
	unsigned char md[16]= {0};
	MD5_Final(md,&ctx);
	for (int i = 0; i < 16; ++i)
	{
		sprinf(&result[i*2],"%02x",md[i]);
	}
}
int main ()
{
	char result[33]={0};
	getMD5("hello,MD5",result);
	cout << result <<endl;
	
}
