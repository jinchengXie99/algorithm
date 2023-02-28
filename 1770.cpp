/*************************************************************************
	> File Name: 1770.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 日  3/27 23:51:47 2022
 ************************************************************************/

#include<iostream>
#include <queue>
using namespace std;
 int main()
{

	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	int i = 1;
	while (1)
	{
		if (i%3==0 ) q.pop();
		else if (q.size() != 1) {
		int d = q.front();
		q.pop();
		q.push(d);
		}else if (q.size()==1) {cout << q.front ();return 0;}
		i++;
		
	}
	return 0;
}
