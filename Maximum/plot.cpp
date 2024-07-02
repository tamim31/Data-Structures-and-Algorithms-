#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int i,j,k=5,m,n;
void insertsort(int a[],int k)
{
    k=5;
    int i,j,item;
    for(j=1;j<k;j++)
    {
        item=a[j];
    i=j-1;
    while(i>=0&&a[i]<item)
    {
        a[i+1]=a[i];
        i=i-1;
    }
    a[i+1]=item;
    }
}
void sort(int b[],int k)
{
    k=5;
    int i,j,item;
    for(j=1;j<k;j++)
    {
        item=b[j];
    i=j-1;
    while(i>=0&&b[i]<item)
    {
        b[i+1]=b[i];
        i=i-1;
    }
    b[i+1]=item;
    }
}
void algo1(int a[])
{
    int k;
    k=5;
    insertsort(a,k);
    for (j= 0;j< k;j++)
        cout << a[j] << " ";
    cout << endl;
    int item,i;

    i=k;
    for(j=k;j<n;j++)
    {
        item=a[j];
    i=k-1;
    while(i>=0&&a[i]<item)
    {
        a[i+1]=a[i];
        i=i-1;
    }
    a[i+1]=item;
    }
   
}
void algo2(int b[])
{
    sort(b,n);

}
int main()
{
    cout << "\nRunning....\n";
    FILE *fp = NULL, *pl = NULL, *fd = NULL;
    fp = fopen("algo1.tmp", "w");
    fd = fopen("algo2.tmp", "w");
    
    for (int cycle = 1; cycle <= 15; cycle++)
    {
        LARGE_INTEGER frequency;
        LARGE_INTEGER t1, t2;
        double bothtime, algo1time, algo2time;

        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
        srand(time(0));
        n = n + 50;
        int a[n + 1], b[n + 1];
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 10000;
            b[i] = a[i];
            
        }
        QueryPerformanceCounter(&t2);
        bothtime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
        algo1(a);
        QueryPerformanceCounter(&t2);
        algo1time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        fprintf(fp, "%d %lf\n", n, algo1time + bothtime);

         QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
        algo2(b);
        QueryPerformanceCounter(&t2);
        algo2time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        fprintf(fd, "%d %lf\n", n, algo2time + bothtime);

       
    }

    char *comm[] = {"set title \"Time plot\"", 
    "plot 'algo1.tmp' lt 7 lw 2 lc 1 w l",
     "replot 'algo2.tmp' lt 7 lw 2 lc 2 w l"
     };
    pl = _popen("gnuplot -persist", "w");
    for (int i = 0; i < 3; i++)
        fprintf(pl, "%s\n", comm[i]);

    return 0;
}