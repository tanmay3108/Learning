#include<iostream>
#include<list>
#define N 1000
#define failed 1
using namespace std;
int indegree[N];
int order[N];
int counter=0;
list<int> que;
list<int>::iterator top;//in case required
int f=0;
struct graph
{
	int a[N][N];
	int v;
	int e;
};

void sort(struct graph *g)
{
	while(que.size()!=0)
	{
		int v=que.front();
		que.pop_front();
        order[++counter]=v;
        
        for(int i=1;i<=g->v;i++)
        {
        	if(g->a[v][i])
        		if(--indegree[i]==0)
        			que.push_back(i);
        }
		
	}
	if(counter!=g->v)
		f=failed;
}
int main()
{
	graph g;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		g.a[i][j]=0;
	}
	
	cout<<"Enetr the number of Vertex and edgese"<<endl;
	cin>>g.v;
	cin>>g.e;
	int t=g.e;
	cout<<"Enter the edges"<<endl;
	while(t--)
	{
		int i;
		int j;
		cin>>i;
		cin>>j;
		g.a[i][j]=1;

	}
	cout<<endl;
	
     
	//calculating indegree
	for(int i=1;i<=g.v;i++)
	{
		int sum=0;
		for (int j=1;j<=g.v;j++)
		{
			sum=sum+g.a[j][i];
		}
		indegree[i]=sum;
		if(sum==0)
		que.push_back(i);
//		cout<<"Indegree of "<<i<<"is "<<sum<<endl;
   }
   sort(&g);
   if(f)
   {
   	cout<<"Sandro fails."<<endl;
   	return 0;
   }
   for(int i=1;i<=g.e;i++)
  	cout<<order[i]<<endl;
   //top=que.begin();
   //cout<<que.size();
return 0;
}
