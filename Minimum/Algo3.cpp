#include<bits/stdc++.h>
using namespace std;
void insertsort(int a[],int n)
{
    int i,j,item;
    for(j=1;j<n;j++)
    {
        item=a[j];
    i=j-1;//sorted array last data,,,
    //ze card ta bicana take ami tolchi,ota sorted
    while(i>=0&&a[i]>item)
    {
        a[i+1]=a[i];
        i=i-1;
    }
    a[i+1]=item;
    }
}
int main()
{
    int n,j,a[1000];
    cin>>n;
    for(j=0;j<n;j++)
    {
        cin>>a[j];
    }
    insertsort(a,n);
    for (j= 0;j< n;j++)
        cout << a[j] << " ";
    cout << endl;
    cout<<a[0]<<endl;
}
