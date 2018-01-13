#include<iostream>
#include<cmath>
using namespace std;
int arr[100][100]={0};
int pos[100][3];

bool valid(int i,int j)
{
	if((i>10||i<10||j>10||j<10)&&(arr[i][j]!=0))
		return 0;
	else
	 return 1;
}

void logic()
{
	int n,i,x,y,iteration;
	cout<<"Enter the number of bacteria";
	cin>>n;
	cout<<"Enter the position of the bacteria";
	int t=n;
    i=1;
	while(t--)
	{
		cout<<"Enetr the position for the "<<i<<"th bacteria";
		cin>>pos[i][1];
		cin>>pos[i][2];

		i++;
	}

    x=pos[1][1];
    y=pos[1][2];
    arr[x][y]=1;
    while(true)
    {

        for(int x=1;x<=10;x++)
        {

		for(int y=1;y<=10;y++)
		{
           
           if(arr[x][y]==1)
           {

           	if(valid(x+1,y))
    				arr[x+1][y]=-1;
    		if(valid(x-1,y))
    				arr[x-1][y]=-1;
    		if(valid(x,y+1))
    				arr[x][y+1]=-1;
    		if(valid(x,y-1))
    				arr[x][y-1]=-1;	
    			      
            }

        
    
    }
        
	}
	for(int m=1;m<=10;m++)
		{
			for(int p=1;p<=10;p++)
			{
				if(arr[m][p]==-1)
					arr[m][p]=1;
				cout<<arr[m][p];
	    	}	cout<<endl;
         }

       	int f;
		cout<<"Press to continue"<<endl;
		cin>>f;    	

}

	

	
}
int main()
{
	logic();
}