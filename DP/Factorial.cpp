
#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
int main()
{
    int n ,s;
        cout<<"enter the number : ";
           cin>>n;
         s=factorial(n);
       
    cout << "Factorial of "<< n << " is " << s << endl;
        
    return 0;
}