/*************************************************************************
	> File Name: 1268.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 21:52:05 2022
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isprime(int n)
{
	if (n<4) return n>1;
	for (int i = 2; i < n/2; i++)
	{

	if (n%i==0) return false;
	}
	return true;
	

}
int main ()
{
	
	int n,x;
	cin >> n >> x;
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		vec.push_back(t);
	}
	sort(vec.begin(),vec.end());
	int len = vec.size();
	int minx= vec[x-1];
	int maxx= vec[len-x];

	if (isprime(maxx-minx)){
		cout << "YES"<<endl;
	} else cout << "NO" << endl;
	
		cout << maxx - minx<< endl;
	return 0;
}
