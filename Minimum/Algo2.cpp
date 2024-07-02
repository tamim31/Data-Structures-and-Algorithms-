#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100],b[100],c[100],n,i,m;
       cin>>n;
        for(i=0; i<n; i++)//0 1 2 3 4 5//index
            //              7 3 1 8 9 2//data
        {
            cin>>a[i];
        }
        for(i=0; i<n; i++)
        {
            for(i=0; i<n; i++)
        {
           b[i]=a[i];
        }
        while(n>1)
        {
          for(i=0;i<=n/2;i++)
          {
              c[i]=min(b[i*2],b[i*2+1]);
          }

          n=n/2;
        }
        }
        //2 5 6 1 3 66 34

        cout<<c[1]<<" " <<endl;
}
