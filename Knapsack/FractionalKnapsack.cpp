#include <bits/stdc++.h>
using namespace std;

 typedef struct {
     int  wt,val;
   float d;
} Item;
void input(Item arr[],int n)
{
   int m,val,wt;
        
   
    for(int i = 0; i <n; i++) 
    {
      cout << "enter "<< i+1 << " Value :  ";
      cin >> arr[i].val;
      cout << "enter "<< i+1 << " Weight : ";
      cin >> arr[i].wt;
    }
}
void display(Item items[], int n)
 {
   int i;
   cout << "values: ";
   for(i = 0; i < n; i++) 
   {
      cout << items[i].val <<" ";
   }
   cout << endl << "weight: ";
   for (i = 0; i< n; i++) 
   {
      cout << items[i].wt <<" ";
   }
   cout << endl;
}

bool compare(Item i1, Item i2) 
{
   return (i1.d > i2.d);
}
float knapsack(Item arr[], int n, int m)
 {
   int i, j, pos;
   Item mx, temp;
   float totalValue = 0, totalWeight = 0;
   for (i = 0; i < n; i++) {
      arr[i].d = arr[i].val / arr[i].wt;
   }
   sort(arr,arr+n, compare);
   for(i=0; i<n; i++)
    {
      if(totalWeight + arr[i].wt<= m)
       {
         totalValue += arr[i].val ;
         totalWeight += arr[i].wt;
      } 
      else
       {
         int remain = m-totalWeight;
         totalValue += (remain * arr[i].d);
         totalWeight += remain;
         break;
      }
   }
   cout << "total weight in bag " << totalWeight<<endl;
   return totalValue;
}

int main()
{
        int m,n,val,wt;
         Item arr[]={{},{},{},{},{},{},{}};
          cout<<"number of objects : ";
            cin>>n;
           input(arr,n);
           display(arr,n);
          
    cout<<"max weight : ";
     cin>>m;
   
     float mxVal = knapsack(arr, n, m);
    cout << "Maximum value we can obtain = "<<mxVal;
    return 0;
}
