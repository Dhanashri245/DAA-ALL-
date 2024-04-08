#include<iostream>
using namespace std;
#define MAX 100
#define TEMP 0
#define PERM 1
#define INFINITY 9999
#define NIL -1
void findPath(int s, int v);
void Dijkstra(int s);
int min_temp();
void create_graph();

int n;
int adj[MAX][MAX];
int predecessor[MAX];
int pathLength[MAX];
int status[MAX];
int main()
{
int s,v;
create_graph();
cout<<"Enter source vertex :";
cin>>s;
Dijkstra(s);
while(1)
{
cout<<"Enter destination vertex(-1 to quit):";
cin>>v;
if(v==-1)
break;
if(v<0||v>=n)
cout<<"Vertex does not exist\n";
else if(v==s)
cout<<"Source and destination are same";
else if(pathLength[v]==INFINITY)
cout<<"There is no path between source to destination";
else
findPath(s,v);
}
}
void Dijkstra(int s)
{
int i ,current;
for(i=0;i<n;i++)
{
predecessor[i]=NIL;
pathLength[i]=INFINITY ;
status[i]=TEMP;
}
pathLength[s]=0 ;
while(1)
{
current = min_temp();
if(current==NIL)
return;
status[current]=PERM;
for(i=0;i<n;i++)
{
if(adj[current][i]!=0 && status[i]==TEMP)
if(pathLength[current]+adj[current][i]<pathLength[i])
{
predecessor[i]=current;
pathLength[i]=pathLength[current]+adj[current][i];
}
}
}
}
int min_temp()
{
int i;
int min = INFINITY;
int k = NIL;
for(i=0;i<n;i++){
if(status[i]==TEMP && pathLength[i]<min)
{
min = pathLength[i];
k = i;
}
}
return k;
}
void findPath(int s, int v)
{
int i,u;
int path[MAX];
int shortdist = 0;
int count = 0;
while(v!=s)
{
count++;
path[count]+v;
u = predecessor[v];
shortdist +=adj[u][v];
v=u;
}
count++;
path[count]=s;
cout<<"Shortest path is\n";
for(i=count;i>=1;i--)
cout<<path[i];
cout<<"The shortest distance is\n"<<shortdist;
}
void create_graph()
{
int i,max_e,o,d,wt;
cout<<"Enter number of vertices";
cin>>n;
max_e=n*(n-1);
for(i=1;i<=max_e;i++)
{
cout<<"Enter edges (-1 to quit)"<<i;
cin>>o>>d;
if((o==-1) && (d==-1))
break;
cout<<"Enter weight for this edge:";
cin>>wt;
if(o>=n ||d>=n ||o<0 ||d<0)
{
cout<<"Invalid edge";
i--;
}
else 
adj[o][d] = wt;
}
}





















