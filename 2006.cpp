#include <iostream>
using namespace std;
template <typename T>
void swap_a(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
int main()
{
    double a = 100;
    double b = 99;
    cout << a << endl;
    cout << b << endl;
    swap_a(a, b);
    cout << a << endl;
    cout << b << endl;
}