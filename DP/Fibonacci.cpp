#include <bits/stdc++.h>
using namespace std;

void fib(int l[],int n)

{

    for(int i=2;i<=n;i++)

    {  

        l[i]=l[i-1]+l[i-2];

    }

}

int main()

{

    int n;
    cout<<"Enter n to find the nth number in the Fibonacci Sequence : ";
    cin>>n;
    int l[n+1];

    l[0]=0;

    l[1]=1;

    fib(l,n);

    cout<<"The nth integer in the Fibonacci Sequence = ";

    cout<<l[n]<<endl;

}