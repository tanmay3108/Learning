#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

/*
* Traverse from roght to left untill array decreases
* from 5 to 8 array increases but at index arr[1]=1 array decreases.
* swap a[1] with the immediate bigger value between 1+1 till n ie. 2 to 5
* since array is increasing from index 5 to index 2 therefore 
 first element on traversing from right to left greater than 
  arr[1] will be immeidate greater automatically
* After swaping arr[1] with immediate greater 
  than a[1] between index2 and 5 number will become 258761
 *Sort all the element from index 2 to 5 
 *And hence element will be 251678 
*/

 //char ch[]={'2','1','8','7','6','5'};
 //char ch[]={'5','3','4','9','7','6'};
 char ch[]={'5','3','4','9','7','8'};
 int size=sizeof(ch)/sizeof(ch[0]);
void display()
{
	for(int i=0;i<size;i++)
	{
		cout<<ch[i];
	}
	cout<<endl;
}
void swap(int index1,int index2)
{
  int a=ch[index1];
  ch[index1]=ch[index2];
  ch[index2]=a;
}
void Isort(int start,int n)
{
	for(int i=start;i<n-1;i++)
	{
		int choosen = ch[i+1];
		int choosenPos = i+1;
		for(int j=i;j>=start;j--)
		{
			if(choosen<ch[j])
			{
				ch[choosenPos]=ch[j];
				ch[j]=choosen;
				choosenPos=j;
			}
			else
			{
				break;
			}
		}
	}

}

void generateNextGreatest()
{
	int swapIndex=-1;
	for(int j=size-1;j>=1;j--)
	{
	  if(ch[j]<=ch[j-1])
	  	continue;
	  if(ch[j]>ch[j-1])
	  {
	  	for(int i=size-1;i>=j;i--)
	  	{
	  		if(ch[i]>ch[j-1])
	  		{
	  			swap(i,j-1);
	  			swapIndex=j-1;
	  			break;
	  		}
	  	}
	  }
	  break;
	}
	display();
	Isort(swapIndex+1,size);
}

int main()
{
 
 display();
 generateNextGreatest();
 display();

}