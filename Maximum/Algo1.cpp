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

        m=a[0];
        for(i=1; i<n; i++)
        {
            if(m>a[i])
            {
                m=a[i];
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

