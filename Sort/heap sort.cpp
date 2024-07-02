#include<bits/stdc++.h>
using namespace std;
void heapify(int a[], int n, int i)
{
    int big,l,r;
    big=i;
    l =2*i+1; r=2*i+2;
    if(n>l&& a[l]>a[big])
        {
            big= l;
        }
    if(n>r&& a[r]>a[big])
        {
            big= r;
        }
    if(big!= i)
       {
            swap(a[i], a[big]);
            heapify(a, n, big);
       }
}
void heapSort(int a[], int n)
{
    for (int i=n/2-1;i>=0;i--)
        {
            heapify(a, n, i);
        }
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int main()
{
    while(1)
    {

    int a[9900],n,i;
    cout<<"number of elements : "<<endl;
    cin>>n;
    cout<<" elements : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    heapSort(a, n);
    cout<<"Sorted array is : "<<endl;
    for(i=0;i<n;i++)
        {
            cout<<a[i]<< " ";
        }
        cout<<endl;
    }
}
