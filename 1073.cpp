/*************************************************************************
	> File Name: 1073.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 六  2/26 17:13:28 2022
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int str_int(string str)
{
	stringstream sstream;
	sstream << str;
	int b;
	sstream >> b;
	return b;
}
int main ()
{

	int sum = 0;
	string str;
	while (cin >> str)
	{
		string :: size_type a, b;
		a = str.find_first_of("+-");
		b = str.find_first_of('=');
		int x, c, y;
		x = str_int(str.substr(0,a));
		y = str_int(str.substr(a+1,b));
		if (str.find('?')==-1){
			c = str_int(str.substr(b+1));
			if (str[a]=='+'&& x+y==c)sum++;
			else if (x-y==c) sum++;
		}

	}
	cout << sum << endl;
	return 0;
}
