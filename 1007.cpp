/*************************************************************************
	> File Name: 1007.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/ 8 22:41:53 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int x;
	cin>>x; 
	if(x>=1&&x<10){
		x=2*x-1;
	}else if(x>=10){
		x=3*x-11;
	}
	cout << x << endl;
	return 0;
}
