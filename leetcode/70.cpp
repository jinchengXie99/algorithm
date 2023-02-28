/*************************************************************************
	> File Name: 70.cpp
	> Author: Jincheng Xie
	> Mail: chengdiy@foxmail.com
	> Created Time: 三  6/15 10:52:53 2022
 ************************************************************************/

#include<iostream>
#include <map>
using namespace std;
int climbStairs(int n) {  //方法一： 依次累加

        int a=1;
        int b=2;
        if ( n == 1 ) return 1;
        if ( n == 2 ) return 2;
        int sum = 0;
        for (int i = 0; i < n-2; i++){
            sum = a + b;
            a = b;
            b = sum;
        }
         return sum;

    }


int main (){


	cout << climbStairs(35) << endl;

}
// 方法二 ： 递归  不好超时
class Solution {
public:
    int climbStairs(int n) {

        if (n==1)return 1;
        if (n==2)return 2;
        
        map<int, int> m;
        m.insert(pair<int,int>(1,1));
        m.insert(pair<int,int>(2,2));

        map<int,int>::iterator iter;
        iter = m.find(n);

        if (  iter != m.end() ){
            return iter->second;
        }
        else {
            int ret = climbStairs(n-1)+climbStairs(n-2);
            m.insert(pair<int, int>(n,ret));
            return ret;

        }


    }
};