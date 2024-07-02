#include<bits/stdc++.h>
using namespace std;
class Bubble
{
public:
    void print()
    {
         int a[1000],p,i,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(p=0;p<n-1;p++)
    {    for(i=0;i<n-p-1;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
            }
        }
    }
      for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    }
};
int main()
{
      Bubble obj;
    obj.print();
    return 0;
}
