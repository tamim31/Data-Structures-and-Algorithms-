
#include <bits/stdc++.h>
using namespace std;

int MatrixChainMultiplication(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
 
    for (i=1; i<n; i++)
        m[i][i] = 0; 

    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX; 
 
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;  
                }
            }
        }
    }
    return m[1][n-1];  

 
}
 
int main()
{
    int n,i,p;
    cout<<" number of matrices"<<endl;
    cin>>n;
    n++;

    int a[n];
 
    cout<<"enter dimensions of the matrix"<<endl;
 
    for(i=0;i<n;i++)
    {
        cout<<"enter dimension d"<<i<<" :: ";
        cin>>a[i];
    }
 
    int s = sizeof(a)/sizeof(a[0]);
 
    cout<<"Minimum number of multiplications is "<<MatrixChainMultiplication(a, s);
 
    return 0;
}