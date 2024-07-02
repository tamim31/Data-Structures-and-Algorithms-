#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main()
{
    int a[100],n,i,m;
       cin>>n;
        for(i=0; i<n; i++)//0 1 2 3 4 5//index
            //              7 3 1 8 9 2//data
        {
            cin>>a[i];
        }
        m=a[0];//7
        for(i=1; i<n; i++)//1 2 3 4 5
            //              3 1 8 9 2
        {
            if(m>a[i])//7>3//3>1//1>8 false,,if dokbe na,loop take break hoye jabe and m print korbe,
            {
                m=a[i];//m=3//m=1
            }
        }

        cout<<m<<endl;
}
