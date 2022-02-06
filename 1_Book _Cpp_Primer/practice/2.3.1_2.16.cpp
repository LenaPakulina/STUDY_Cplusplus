#include <iostream>

using namespace std;

int main()
{
    // int ival = 1024;
    // int *pi = &ival;
    
    // int **ppi = &pi;
    
    // cout << ival << " " << *pi << " " << **ppi << " ";
    
    int i = 42;
    int *p;
    int *&r = p; // ссылка на указатель
    r = &i;
    *r = 0;
    
    cout  << i;

    return 0;
}