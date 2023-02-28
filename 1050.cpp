/*************************************************************************
	> File Name: 1050.cpp
	> Author: Chengxing
	> Mail:  chengdiy@foxmail.com
	> Created Time: 一  2/21 21:41:15 2022
 ************************************************************************/

#include<iostream>
#include <string>
#include <iomanip>
using namespace std;
class Student{
	public:
		string name;
		string num;
		float c1,c2,c3;
};
void input(int n,Student stu[]){

	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].num >>stu[i].name >>stu[i].c1 >>stu[i].c2 >> stu[i].c3;
	}
};
void output(int n, Student stu[]){

	for (int i = 0; i < n; i++)
	{
		cout << stu[i].num << "," << stu[i].name << "," << stu[i].c1 
			 << ","<<stu[i].c2<<","<<stu[i].c3 << endl;
	}

};
int main ()
{

	int n;
	cin >> n;
	Student stu[n];
	input(n,stu);
	output(n,stu);

	return 0;
}
