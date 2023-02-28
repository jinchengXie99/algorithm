#include <iostream>
#include <climits>

    int reverse(int x) {

        int t=0;
        int ret=0;
        while(x!=0){
            if (ret > INT_MAX/10 || ret < INT_MIN)return 0;
            t = x%10;
            x/=10;
            ret = ret * 10 + t;
           
        }
        
        return ret;

    }

int main ()
{

	int i;
	std::cin >> i;
	std::cout << reverse(i) << std::endl;
}
