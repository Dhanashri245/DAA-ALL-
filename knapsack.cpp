#include<iostream>
using namespace std;
void knapsack(int n,float weight[], float profit[],float capacity)
{
float X[20],tp=0;

int i,j,u;
u=capacity;
for(i=0;i<n;i++)
X[i]=0.0;
for(i=0;i<n;i++)
{
if(weight[i]>u)
break;
else
{
X[i]=1.0;
tp=tp+profit[i];
u=u-weight[i];
}
}
if(i<n)
X[i]=u/weight[i];
tp=tp+(X[i]*profit[i]);
cout<<"the result vector is= ";
for(i=0;i<n;i++)
{
cout<<X[i];
}
cout<<"\nMaximum profit is= "<<tp;
}
int main()
{
float weight[20],profit[20],capacity;
int num,i,j;
float ratio[20],temp;
cout<<"Enter no of object";
cin>>num;
cout<<"\nEnter weights and profit for each object";
for(i=0;i<num;i++)
{
cin>>weight[i]>>profit[i];
}
cout<<"\nEnter capacity of knapsack";
cin>>capacity;

for(i=0;i<num;i++)
{
ratio[i]=profit[i]/weight[i];
}
for(i=0;i<num;i++)
{
for(j=i+1;j<num;j++)
{
if(ratio[i]<ratio[j])
{
temp=ratio[j];
ratio[j]=ratio[i];
ratio[i]=temp;

temp=weight[j];
weight[j]=weight[i];
weight[i]=temp;

temp=profit[j];
profit[j]=profit[i];
profit[i]=temp;

}
}
}
knapsack(num,weight,profit,capacity);
return 0;
}
























