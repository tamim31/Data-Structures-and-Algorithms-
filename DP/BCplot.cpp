#include <bits/stdc++.h>
#include<windows.h>
using namespace std;
int n, i, k, j, answer[5],l,m,p;
int binomialCoeff(int p, int k)
{
    if (k > p)
        return 0;
    if (k == 0 || k == p)
        return 1;
    return binomialCoeff(p- 1, k - 1)
           + binomialCoeff(p - 1, k);
}
 
int main()
{
    cout << "\nRunning....\n";
    FILE *fp = NULL, *pl = NULL;
    fp = fopen("bc.tmp", "w");
    for (int cycle = 1; cycle <= 15; cycle++)
    {
        LARGE_INTEGER frequency;
        LARGE_INTEGER t1, t2;
        double bothtime, algo1time;

        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
        srand(time(0));
        
            p= rand() % 10000;
             k= rand() % 10000;
            
        QueryPerformanceCounter(&t2);
        bothtime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

         QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
        binomialCoeff(p, k);
        QueryPerformanceCounter(&t2);
        algo1time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        fprintf(fp, "%d %lf\n", p, algo1time + bothtime);
    }
    char *comm[] = {"set title \"Time plot\"", 
    "plot 'bc.tmp' lt 7 lw 2 lc 1 w l",
     };
    pl = _popen("gnuplot -persist", "w");
    for (int i = 0; i < 2; i++)
        fprintf(pl, "%s\n", comm[i]);
}