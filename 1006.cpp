/*************************************************************************
	> File Name: 1006.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
////	> Created Time: 二  2/ 8 22:02:55 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
	int a[3];
	cin >> a[1]>>a[0]>>a[2];
	sort(a,a+3,greater<int>());
	//还可以用两次max（）函数比较两次最大值   
	cout << a[0]<<endl;
	return 0;
}
