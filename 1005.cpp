/*************************************************************************
	> File Name: 1005.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/ 8 21:39:09 2022
 ************************************************************************/

#include<iostream>
#include<iomanip>// 在C++中的精度控制由iomanip 控制   fixed表示小数小数点后的精度
				 // setprecision 默认是取几位有效数字 
using namespace std;
int main ()
{
	float x;
	float T;
	cin >> x;
	T = (x - 32)*5/9;
	cout<<fixed<< setprecision(2) <<"c="<< T << endl;
	return 0;
}
