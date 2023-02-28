/*************************************************************************
	> File Name: 1014.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/11 16:59:41 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	
	 int n;
	 cin >> n;
	 long long sum=0;
	 long long t = 1;//int类型装不下
	 for (int i=1;i <= n;i++)
	 {
		 t*=i;
		 sum+=t;
	 }

	 cout << sum << endl;
	return 0;
}
