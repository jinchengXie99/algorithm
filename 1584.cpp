/*************************************************************************
	> File Name: 1584.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  2/ 8 23:14:42 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{
	string str;
	cin>>str;
	int len=str.length();
	for(int i = 0; i < len; i++){
	if (str[i]=='a'||str[i]=='e'||str[i]=='o'||str[i]=='u'||str[i]=='i')
		{
			cout<< i+1<< endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}
