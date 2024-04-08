#include<iostream>
using namespace std;
void quick(int a[],int l,int up);
int partition(int arr[],int low,int up);
int main()
{
int arr[]={4,6,1,8,5};
int n=5,i;
cout<<"The unsorted array is";
for
(i=0;i<n;i++)
{
cout<<"\n"<<arr[i];
}
quick(arr , 0, n-1);
cout<<"Sorted array is ";
for(i=0;i<n;i++)
{
cout<<"\n"<<arr[i];
}
}
void quick(int a[],int l,int up)
{
int pvtloc;
if(l>=up)
return;
pvtloc = partition(a,l,up);
quick(a,l,pvtloc-1);
quick(a,pvtloc+1,up);
}
int partition(int arr[],int low,int up)
{
int t,pvt;
int i=low+1;
int j=up;
pvt=arr[low];
while(i<=j)
{
while(arr[i]<pvt)
{
i++;
}
while(arr[j]>pvt)
{
j--;
}
if(i<j)
{
t=arr[i];
arr[i]=arr[j];
arr[j]=t;
i++;
j--;
}
else
{
i++;
}
}
arr[low]=arr[j];
arr[j]=pvt;
return j;
}

