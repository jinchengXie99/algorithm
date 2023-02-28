/*************************************************************************
	> File Name: 1051.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 二  3/ 8 22:00:05 2022
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;
class student{
	public:
		string number; //学号
		string name;	//姓名
		int a,b,c;   //三门成绩		
		int sum_abc(void) //总成绩
		{
			return a+b+c;
		}
};
int main()
{
	int n;
	cin >> n;
	student *sd = new student[n];
	int MAX=0;
	int av[3]={0}; //三门平均成绩
	for (int i = 0;  i < n; i++)
	{
		cin >> sd[i].number;
		cin >> sd[i].name;
		cin >> sd[i].a >> sd[i].b >> sd[i].c;
		av[0]+=sd[i].a;
		av[1]+=sd[i].b;
		av[2]+=sd[i].c;
		if (i > 0 && (sd[i].a+sd[i].c+sd[i].b) > (sd[MAX].a+sd[MAX].c+sd[MAX].b)){
			MAX = i;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		av[i] /= n;
		if (i!=0)cout << " ";
		cout << av[i];
		if (i == 2) cout << endl;
	}

	cout << sd[MAX].number << " " << sd[MAX].name << " " << sd[MAX].a << " " <<sd[MAX].b<< " "<< sd[MAX].c;
	return 0;
}
