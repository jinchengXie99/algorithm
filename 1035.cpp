/*************************************************************************
	> File Name: 1035.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 四  2/17 15:26:22 2022
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
void fun(string &str)
{
	int len = str.length();
	int a = 0,b = 0,c = 0,d = 0;//分别表示字母 数字 空格 其他字符 数
	for (int i = 0; i < len; i++)
	{
		if ((str[i]>='a'&&str[i]<='z')||(str[i] >= 'A'&& str[i] <= 'Z'))a++;
		else if (str[i]>='0' && str[i] <= '9' )b++;
		else if (str[i] == ' ')c++;
		else d++;
	}
	cout << a << " " << b <<" " << c << " " << d << endl;
}
int main ()
{
	string str;
	getline(cin,str);
	fun(str);

	return 0;

}
