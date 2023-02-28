/*************************************************************************
	> File Name: 1021.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/15 15:37:38 2022
 ************************************************************************/

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main ()
{


	double a,b,x;
	cin >> a;
	x = a/2;
	while(1){
	b = (x + a/x)/2;
	if (fabs(x - b) < 0.00001){
		break;
	}
	x = b;
	}
	cout << fixed << setprecision(3) << b << endl;
	return 0;
}
