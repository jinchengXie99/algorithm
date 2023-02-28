/*************************************************************************
	> File Name: 1061.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/24 22:02:52 2022
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{
	int i = 20;
	int sum = 0;
	int rn = 0;
	while(i--){
	int t;
	cin >>t;
	if (t < 0)rn++;else sum+=t;
	}

	cout << rn << endl;
		cout << fixed << setprecision(2) <<(float)sum/(20.0 - rn) << endl;
	return 0;
}
