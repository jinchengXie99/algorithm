/*************************************************************************
	> File Name: 1013.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 五  2/11 16:32:53 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	int sum=0;
	int t=2;
	if (n==0){cout<<"0"<<endl;return 0;}

	for(int i=1;i<=n;i++){
		sum+=t;
		t=t*10+2;
	}
	cout << sum<< endl;
	return 0;
}
