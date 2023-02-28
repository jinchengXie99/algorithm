/*************************************************************************
  > File Name: 6.cpp
  > Author: Chengxing
  > Mail:  chengdiy@foxmail.com
  > Created Time: 三  3/16 13:28:51 2022
 ************************************************************************/
#include <iostream>
#include <string>
using namespace std;

struct free_throws{
	string name;
	int made;
	int attempts;
	float percent;
};
void set_pc(free_throws &ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0 * float(ft.made)/float(ft.attempts);
	else ft.percent = 0;

}
void display (const free_throws &target)
{
	cout << "Name :" << target.name << endl;
	cout << "Made :" << target.made << endl;
	cout << "Attempts :" << target.attempts << endl;
	cout << "Percent :" << target.percent << endl;
}
int main (void)
{
	free_throws one = {"Ruck",13,14};	
	free_throws tow = {"Time",2,12};
	free_throws three = {"Jason",42,62};
	free_throws four = {"Micheal",52,82};
	free_throws five = {"Rose",32,18};
	free_throws six = {"team",27,19};
	set_pc(one);
	display(one);
	return 0;
}
