//Detects cycle as well as do dfs for undirected graph
//It can even detect the cycle in a tree since tree is an undiected graph
//Cannnot detect the cycle in directed graph
#include<iostream>
#define cycle 1
#define nocycle 0
int N;
//#define N 4//define n 1 more than the no.vertex required
using namespace std;
int a[100][100]={0};
int visited[100]={0};
int flag=nocycle;
int  dfs(int v,int p)
{

	
		visited[v]=1;
	    cout<<v;
	

	for(int i=1;i<N;i++)
		{
           if(a[v][i])
           {

           if(visited[i]&&(v!=p))
           flag=cycle;
           if(!visited[i])
           	dfs(i,v);
        }  
    }

}

int main()
{

    
    int type;
    int V; 
	cout<<"Enter the no of vertex"<<endl;
	cin>>N;
	N++;
	cout<<"Enetr u for 1 for undirected and 2 for directed"<<endl;
	cin>>type;
	cout<<"enter the number of edges"<<endl;
	cin>>V;
	int c=V;
	cout<<"Enter the edges";
	if(type==1)
	{

		while(c--)
		{ 

			int V1,V2;
			cin>>V1;
			cin>>V2;
			a[V1][V2]=1;
			a[V2][V1]=1;

		}
    }
    else
    {	
    while(c--)
			{ 

				int V1,V2;
				cin>>V1;
				cin>>V2;
				a[V1][V2]=1;
				

		   }	
	}



	dfs(1,1);
	if(flag)
		cout<<"Cycle";
	else
		cout<<"Not a Cylce";
}
