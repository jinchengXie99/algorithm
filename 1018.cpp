/*************************************************************************
	> File Name: 1018.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/14 21:55:00 2022
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{
	double sum = 0.0;;
	double a = 1.0;
	double b = 2.0;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		sum += b/a;
		b=a+b;
		a=b-a;
	}

	cout << fixed << setprecision(2) << sum << endl;
	return 0;

}
