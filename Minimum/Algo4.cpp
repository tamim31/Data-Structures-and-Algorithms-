#include<bits/stdc++.h>
using namespace std;
class Traverse
{
public:
    int n,a[100],i,m;
    void getArray()
    {
        cout<<"number of element : "<<endl;
        cin>>n;
        cout<<"elements : "<<endl;
        for(i=0; i<n; i++)
        {
            cin>>a[i];
        }

    }
    void print()
    {

        int flag =1,i=0;
        while(flag==1)
        {
            i++;
           m=a[i];
           flag =0;
           for(int j=1;j<n;j++)
           {
               if(m>a[j])
               {
                   flag=1;
               }
           }
        }


        cout<<"min value : "<<endl;
          cout<<m<<endl;
    }
};
int main()
{
    Traverse obj;
    obj.getArray();
    obj.print();
    return 0;
}

