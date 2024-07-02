#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int n, i, k, j, answer[5],l,m;
void insertsort(int t[],int n)
{
    int i,j,item;
    for(j=1;j<n;j++)
    {
        item=t[j];
    i=j-1;//sorted array last data,,,
    //ze card ta bicana take ami tolchi,ota sorted
    while(i>=0&&t[i]>item)
    {
        t[i+1]=t[i];
        i=i-1;
    }
    t[i+1]=item;
    }
}
void merge( int a[], int l,int m,int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2],i=0,j=0;
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    int k = l;
    while (i < n1 && j < n2)
     {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort( int a[],int l,int r)
{
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
}
void heapify(int b[], int n, int i)
{
    int big,l,r;
    big=i;
    l =2*i+1; r=2*i+2;
    if(n>l&& b[l]>b[big])
        {
            big= l;
        }
    if(n>r&& b[r]>b[big])
        {
            big= r;
        }
    if(big!= i)
       {
            swap(b[i], b[big]);
            heapify(b, n, big);
       }
}
void heapSort(int b[], int n)
{
    for (int i=n/2-1;i>=0;i--)
        {
            heapify(b, n, i);
        }
    for (int i = n - 1; i > 0; i--)
    {
        swap(b[0], b[i]);
        heapify(b, i, 0);
    }
}
int main()
{
    cout << "\nRunning....\n";
    FILE *fp = NULL, *pl = NULL, *fd = NULL, *fm = NULL;
    fp = fopen("mergeSort.tmp", "w");
    fd = fopen("insertionSort.tmp", "w");
    fm = fopen("heapSort.tmp", "w");
    
    for (int cycle = 1; cycle <= 15; cycle++)
    {
        LARGE_INTEGER frequency;
        LARGE_INTEGER t1, t2;
        double bothtime, algo1time, algo2time, algo3time;

        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
        srand(time(0));
        n = n + 50;
        int a[n + 1], b[n + 1], t[n + 1];
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 10000;
            b[i] = a[i];
            t[i] = a[i];
        }
        QueryPerformanceCounter(&t2);
        bothtime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

         QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
        mergeSort(a,l,m);
        QueryPerformanceCounter(&t2);
        algo2time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        fprintf(fp, "%d %lf\n", n, algo2time + bothtime);

        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
        insertsort(t,n);
        QueryPerformanceCounter(&t2);
        algo1time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        fprintf(fd, "%d %lf\n", n, algo1time + bothtime);

       

        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&t1);
        heapSort(b,n);
        QueryPerformanceCounter(&t2);
        algo3time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
        fprintf(fm, "%d %lf\n", n, algo3time + bothtime);

       
    }

    char *comm[] = {"set title \"Time plot\"", 
    "plot 'mergeSort.tmp' lt 7 lw 2 lc 1 w l",
     "replot 'insertionSort.tmp' lt 7 lw 2 lc 4 w l", 
     "replot 'heapSort.tmp' lt 7 lw 2 lc 2 w l"};
    pl = _popen("gnuplot -persist", "w");
    for (int i = 0; i < 4; i++)
        fprintf(pl, "%s\n", comm[i]);

    return 0;
}