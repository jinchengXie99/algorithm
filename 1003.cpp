/*************************************************************************
	> File Name: 1003.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/ 8 21:26:26 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main (){

	char a[5];
	cin>> a;
	for (int i=0;a[i]!='\0';i++)cout<<(char)(a[i]+4);
	cout<< endl;
	return 0;

}
