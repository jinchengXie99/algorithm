/*************************************************************************
	> File Name: 1057.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/24 21:41:26 2022
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{
    float  x,y;
	cin >> x;
	if(x<1)y = x;else if (x>=1||x<10)y=2*x-1;else y=x*3-11;
	cout << fixed << setprecision(2) << y<< endl;

	return 0;
}
