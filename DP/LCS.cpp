#include <bits/stdc++.h>
using namespace std;
 
int max(int a, int b);
 
int lcs( char *s1, char *s2, int m, int n )
{
    if (m == 0 || n == 0)
            return 0;
    if (s1[m-1] == s2[n-1])
        return 1 + lcs(s1, s2, m-1, n-1);
    else
        return max(lcs(s1, s2, m, n-1), lcs(s1, s2, m-1, n));
}

int max(int a, int b)
{
     return (a > b)? a : b;
}
 
int main()
{
    char s1[100],s2[100];
    cin>>s1>>s2;
     
    int m = strlen(s1);
    int n = strlen(s2);
     
    cout<<"Length of LCS is "<< lcs( s1, s2, m, n ) ;
    
}