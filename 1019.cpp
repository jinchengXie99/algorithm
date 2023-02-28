/*************************************************************************
	> File Name: 1019.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/14 22:03:46 2022
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{
	double M;
	int N;
	cin >> M >> N;
	double h = M,sh = 0.0; 
	sh += h;
	for (int i = 0; i < N; i++)
	{
		h /= 2.0;
		if (i != N-1){
			sh += 2*h;
		}
	}
	cout << fixed << setprecision (2) << h << " " << sh << endl;
	return 0;
}
