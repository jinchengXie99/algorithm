/*************************************************************************
	> File Name: 1038.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/18 20:31:43 2022
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<iomanip>
#define S (a+b+c)/2
#define area(a,b,c) sqrt(S*(S-a)*(S-b)*(S-c))
using namespace std;
int main ()
{

	double a,b,c;
	cin >> a >> b >> c;
	double are = area(a,b,c);
	cout << fixed << setprecision(3)<< are << endl;

	return 0;

}

