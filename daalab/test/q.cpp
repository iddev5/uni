#include<bits/stdc++.h>
#include<time.h>
int z=1;
using namespace std;
int findpivot(int a[],int start, int end){
    int st = start;
    if(z){
      cout<<"Enter pivot position between "<<start<<" and "<<end;
      cin>>st;
      z=0;
    }
    int pivot = a[st];
    int i=start,j=end;
    while(i<=j){
        while(a[i]<=pivot&&i<=end)i++;
        while(a[j]>pivot&&j>=start)j--;
        if(i<j)swap(a[i],a[j]);
    }
    swap(a[start],a[j]);
    return j;
}
void quicksort(int a[],int start,int end){
    if(start>=end)return;
    int partition = findpivot(a,start,end);
    quicksort(a,start,partition-1);
    quicksort(a,partition+1,end);
}

int main(){
       clock_t start_t,end_t;
       int n,p;
       string s;
       double t0,t1,t2,t3;
    cout<<"Enter number of elements : ";
    cin>>n;
    int a[n];
    double t[4];
    double min = 0;
       for(int i=0;i<4;i++){
        cout<<"Enter elements : ";
        if(i==0){
            cout<<"for sorted array in ascending order :  ";
            s="sorted array in ascending order";
            }

        else if(i==1){
            cout<<"for sorted array in decending order :  ";
            s="sorted array in decending order";
            }

        else if(i==2){
            cout<<"for unsorted array : ";
            s ="unsorted array";
            }
        else if(i==3){
            cout<<"for a mixed array(sorted & unsorted) : ";
                s ="mixed array(sorted & unsorted) : ";
                }

        for (int j=0;j<n;j++)cin>>a[j];
    start_t = clock();
    double k1= (double)start_t/CLOCKS_PER_SEC;

    quicksort(a,0,n-1);
    end_t = clock();
     double k2 = (double)end_t/CLOCKS_PER_SEC;
    cout<<"After sorting array is : ";
    for (int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Start time for "<<s <<"="<<k1<<endl;
   
   cout<<"End time for "<<s<<"="<<k2<<endl;
   t[i]=k2-k1;
  
   cout<<"Time taken "<<fixed<<setprecision(7)<<t[i]<<endl;
       }
     min=t[0];
     p=0;
     for(int l=0;l<4;l++){
            if(min>t[l]){
    min=t[l];
    p=l;
   }
     }
     cout<<"After progrram executiopn it is observed that ";
     if(p==0)cout<<"Sorted array in ascending order";
     if(p==1)cout<<"Sorted array in decending order";
     if(p==2)cout<<"Unsorted array";
     if(p==3)cout<<"mixed array(sorted & unsorted)";
     cout<<" takes least time";
     
       }
