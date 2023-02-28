/*************************************************************************
	> File Name: 1063.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/24 22:12:16 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a = 0;
	int b = 0; 
	int c = 0;
	int d = 0;
	string str;
	getline(cin,str);
	int i = str.size();
	while (i--)
	{
		if( (str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
		a++;
		else if (str[i]==' ')
		b++;
		else if ( (str[i]>='0'&&str[i]<='9'))
		c++;
		else d++;

	}
	cout << a <<endl;
	cout << b <<endl;
	cout << c <<endl;
	cout << d <<endl;
	return 0;
}

