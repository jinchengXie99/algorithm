/*************************************************************************
	> File Name: 1094.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 16:27:22 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{
	int n ;
	cin >> n;
	getchar();
	while (n--)
	{
		string str;
		getline(cin, str);
		cout << str << endl;
		cout << endl;
		str.clear();
	}
	string str;
	int i=0;
	while (cin>>str)
	{
		if (i==0){
			cout << str ;
			i++;
		} 
			else{
				cout << endl;
				cout << endl;
				cout << str;
		}
	}
	return 0;

}
