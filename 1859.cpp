/*************************************************************************
	> File Name: 1859.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  3/ 4 16:38:47 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{

	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int t = i;
		if (i%2==0) continue;
		else if(t>10&&t<100 ){
			if(t/10==2) continue;
		}else if (t>=100&&t<=1000)
		{
			if (t/10%10==2)continue;
			else if (t/100==2)continue;
		}
		sum+=i;

	}
	cout << sum << endl;
	return 0;
}
