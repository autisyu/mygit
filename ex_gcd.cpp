#include<iostream>
using namespace std;
void ex_gcd(int &x, int &y, int a, int b)
{
    if (b == 0) {
        x = 1, y = 0;     
    } else {
    int tempx, tempy;
    ex_gcd(tempx, tempy, b, a%b);
    x = tempy, y = tempx - a/b * tempy;
    }
}
int main()
{
    int x, y, a, b;
    cin>>a>>b;
    ex_gcd(x, y, a, b);
    cout<<x<<" "<<y<<endl;
    return 0;
}
