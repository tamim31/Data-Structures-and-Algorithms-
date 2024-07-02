#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }


int knapSack(int m, int wt[], int val[], int n)
{
    if (n == 0 || m == 0)
        return 0;
    
    if (wt[n - 1] > m)
        return knapSack(m, wt, val, n - 1);

    else
        return max(
            val[n - 1] + knapSack(m - wt[n - 1],wt, val, n - 1),
            knapSack(m, wt, val, n - 1));
}


int main()
{
    int val[100] ,i,n,m,wt[100];
    cout<<"number of objects : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    cout<<"profits : ";
    for(i=0;i<n;i++)
    {
        cin>>val[i];
    }
     cout<<"max weight : ";
     cin>>m;

    cout <<"maximum profit is : " <<knapSack(m, wt, val, n);
}
