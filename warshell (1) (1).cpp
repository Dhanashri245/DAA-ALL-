#include<iostream>
using namespace std;


#define infi 99999
#define max 100
int n;
int adj[max][max];
int D[max][max];
int pre[max][max];

void createg();
void warshall();
void find_path(int s,int d);
void display(int mat[max][max],int n);

int main(){
	int s,d;
	createg();
	warshall();
	while(1){
	cout<<"Enter the source(-1) to exit: ";
	cin>>s;
	if(s==-1)
	break;
	cout<<"Enter destinaton vertex: ";
	cin>>d;
	if(s<0 || s>n-1||d<0 ||d>n-1){
	cout<<"Enter a valid vertex\n";
	continue;}
	cout<<"Shortest path is :";
	find_path(s,d);
	cout<<"Length of path is "<<D[s][d];
	return 0;
	}
	}
void createg(){
	int i,max_edges,o,d,wt;
	
	cout<<"Enter the number of vertices: ";
	cin>>n;
	max_edges=n*(n-1);
	for(i=1;i<=max_edges;i++){
	cout<<"Enter the edge (-1 -1 to quit) "<<i<<":";
	cin>>o>>d;
	
	
	if((o==-1)&&(d==-1))
	break;
	cout<<"Enter the weight for this edge :";
	cin>>wt;
	
	if(o>=n||d>=n|o<0||d<0){
	cout<<"Invalid edge\n";
	i--;}
	else{
	adj[o][d]=wt;
	}
	}
	}
	
void warshall(){
	int i,j,k;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++){
	if(adj[i][j]==0){
	D[i][j]=infi;
	pre[i][j]=-1;
	
	}
	else{
	D[i][j]=adj[i][j];
	pre[i][j]=i;
	}}
	
	for(k=0;k<n;k++){
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	if(D[i][k]+D[k][j] <D[i][j]){
	D[i][j]=D[i][k]+D[k][j];
	pre[i][j]=pre[k][j];
	}
	}
	cout<<"Shortest path matrix is :\n";
	display(D,n);
	cout<<"Predecessor matrix is :\n";
	display(pre,n);
	
	
	}
	
void find_path(int s,int d){
	int i;
	int path[max];
	
	int count ;
	if(D[s][d]==infi){
	cout<<"No path";
	return;
	
	}
	count=-1;
	do{
	path[++count]=d;
	d=pre[s][d];
	}
	while(d!=s);
	path[++count]=s;
	for(i=count ;i>=0;i--)
	cout<<path[i];
	cout<<"\n";
	}
	
void display(int mat[max][max],int n){
	int i,j;
	for(i=0;i<n;i++){
	for(j=0;j<n;j++)
	cout<<mat[i][j]<<" ";
	
	cout<<"\n";
	}}
