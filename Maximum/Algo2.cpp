#include<bits/stdc++.h>
using namespace std;
class Traverse
{
public:
    int n,a[100],i,b[100],c[100];
    void getArray()
    {
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }
    }
    void print()
    {

        for(i=0; i<n; i++)//0 1 2 3 4  5 6
            //              7 5 4 9 2  8 1
            //               5   4   2    1
            //                 4        1
            //                     1
        {
           b[i]=a[i];
        }
        while(n>1)
        {
          for(i=0;i<=n/2;i++)
          {
              c[i]=min(b[i*2],b[i*2+1]);
          }
        cout<<"pass : ";
          for(i=0;i<=n/2;i++)
              cout<<c[i]<<" " ;
          cout<<endl;
          n=n/2;
        }
//2 5 6 1 3 66 34

        cout<<c[1]<<" " <<endl;

    }
};
int main()
{
    Traverse obj;
    obj.getArray();
    obj.print();
    return 0;
}

