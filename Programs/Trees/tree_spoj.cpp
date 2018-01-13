#include<iostream>
#include<cstring>
#include<cmath>
#define dim 100
using namespace std;
int visited[dim]={0};
static int s;
void dfs(int graph[dim][dim],int v,int parent,int V)
{
	visited[v]=1;
for(int i=1;i<=V;i++)
{	
	if(graph[v][i])
	{
		if(visited[i]&&(i!=parent))
			s=1;
		else if(!visited[i])
			dfs(graph,i,v,V);
	}
}
}
int main()
{
	int graph[dim][dim]={0};
	int v=0;
	int e=0;
	int e1=0;
	int e2=0;
    cin>>v>>e;
    if(e==v-1)
{
    for(int i=1;i<=e;i++)
    {
    	cin>>e1>>e2;
    	graph[e1][e2]=1;
    	graph[e2][e1]=1;
    }
    
    int x=1;
    

    
   dfs(graph,1,-1,v);
   for(int i=1;i<=v;i++)
    	x=x*visited[i];
    if((s==1)||(x==0))
    	cout<<"No"<<endl;
    else
    	cout<<"Yes"<<endl;
}
else
 cout<<"No";
    return 0;
}