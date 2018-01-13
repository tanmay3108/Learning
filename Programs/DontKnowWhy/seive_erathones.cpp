#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int t,a,b;
    cin>>t;
 	while(t--) 
 	{
  		cin>>a>>b;
  		long double arr[100000];
  		for(long double i=2;i<=b;++i)
  		{
  			arr[i]=i;
		}

		int x=2;
		while(x<=b)
		{   
			if(arr[x]==-1)
				{
					x++;
					continue;
				}	
			else
			{
				for(long double i=x+x;i<b+2;i=i+x)
				{
					arr[i]=-1;
 
				}
            x=x+1;
            }
	    }
	    for(long double i=2;i<=b;i++)
	    {
			if(arr[i]==-1)
			continue;
		    cout<<arr[i]<<endl;
		}
	
     }
 }

