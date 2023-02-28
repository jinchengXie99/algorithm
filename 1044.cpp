/*************************************************************************
	> File Name: 1044.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 六  2/19 13:16:24 2022
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main ()
{
	string str;
	vector<string> S;
	for (int i = 0; i < 3; i++ )
	{
		cin >> str;
		S.push_back(str);
	}
	sort(S.begin(),S.end());
	for (int i = 0; i < 3; i++)
	{
	cout << S[i] << endl;
	
	}
	return 0;
}
