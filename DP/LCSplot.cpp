#include <bits/stdc++.h>
#include<windows.h>
using namespace std;
 int n, i, k, j, answer[5],l,m,p;
int max(int a, int b);
string s1,s2;
int lcs( string s1, string s2, int m, int n )
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
    cout << "\nRunning....\n";
    FILE *fp = NULL, *pl = NULL;
    fp = fopen("lcs.tmp", "w");
    for (int cycle = 1; cycle <= 15; cycle++)
    {
        LARGE_INTEGER frequency;
        LARGE_INTEGER t1, t2;
        double bothtime, algo1time;

        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
        srand(time(0));
        
             s1= rand();
             s2= rand();
          m=sizeof(s1);
          n=sizeof(s2);
            
        QueryPerformanceCounter(&t2);
        bothtime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

         QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
         lcs(s1, s2, m-1, n-1);
        QueryPerformanceCounter(&t2);
        algo1time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        fprintf(fp, "%d %lf\n", p, algo1time + bothtime);
    }
    char *comm[] = {"set title \"Time plot\"", 
    "plot 'lcs.tmp' lt 7 lw 2 lc 1 w l",
     };
    pl = _popen("gnuplot -persist", "w");
    for (int i = 0; i < 2; i++)
        fprintf(pl, "%s\n", comm[i]);
}