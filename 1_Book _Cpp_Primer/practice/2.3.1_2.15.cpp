#include <iostream>

using namespace std;

int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;
    
    r2 = 3.145;
    // cout<<r2  << " " << d;
    i = 3.14;
    
    r1 = r2;
    r2 = r1;
    // cout<<r1  << " " << r2;
    
    i = r2;
    r1 = d;
    
    //int &ref = d; так нельзя
    {
        int i, &ri = i;
        i = 5;
        ri = 10;
        cout<<i  << " " << ri;
    }
    

    return 0;
}