#include<bits/stdc++.h>
#include <windows.h>
using namespace std; 
int n,s[300][400];

void parenthesis(int i,int j)
{
              if(i==j)cout<<"A"<<i;
              else {cout<<"(";
              
              parenthesis(i,s[i][j]);
              parenthesis(s[i][j]+1,j);

                 cout<<")";}
}

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
                    s[i][j]=k; 
                }
            }
        }
    }
     for(i=1;i<n;i++)
        {
            for(j=i+1;j<n;j++)cout<<s[i][j]<<" ";
            cout<<endl;
        }
        parenthesis(1,n-1);
 
     return m[1][n-1];   
 
}
 
int main()
{
    int i,j,re;
    double ti;
    LARGE_INTEGER frequency;
    LARGE_INTEGER t1, t2;
    cout<<"Enter number of matrices\n";
    cin>>n;
    n++;
    int arr[n];
    cout<<"Enter dimensions \n";
 
    for(i=0;i<n;i++)
    {
        cout<<"Enter d"<<i<<" :: ";
        cin>>arr[i];
    }
 
    int size = sizeof(arr)/sizeof(arr[0]);
    QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
         MatrixChainMultiplication(arr, size);
        QueryPerformanceCounter(&t2);
        ti = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    
    cout<<"Minimum number of multiplications is "<<re<<endl;
    cout<<"time: "<<ti<<"ms"<<endl;
       
    return 0;

}