/*************************************************************************
	> File Name: 1027.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 三  2/16 20:06:46 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int fun(int a,int b)
{
	return (a % b == 0) ? b : fun(b , a % b);
}
int fun1(int a, int b)
{

return (a*b/(fun(a,b)));
}

int main ()
{
	int a,b;
	cin >> a >> b;
	if (a < b){
		swap(a,b);
	}
	cout << fun(a,b) << " " << fun1(a,b)<< endl;
	return 0;
}
