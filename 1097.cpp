/*************************************************************************
	> File Name: 1097.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  2/27 16:52:17 2022
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin >> n;
	int m = n; //每行输出几个数
	int b = 1;
	for (int i = 1; i <= n; i++)
	{	
		// 测试git更改
		int a = 0; // 第一次数值前面不输出空格
		int t = b; // 输出的数
			b=b+i; // 行首第一个数
		int c = i+1; //每行下一个数的差值
		for (int j = 0; j < m; j++)
		{
			if (a == 0 ) {
			cout << t;
			a++;
			}else
			{
				cout << " " << t ;
			}
			t += c;
			c++;
		}
		cout << endl;
		m--;
	}
	return 0;
}
