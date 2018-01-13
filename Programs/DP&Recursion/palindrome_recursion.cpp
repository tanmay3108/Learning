#include<iostream>
#include<cstring>
using namespace std;
int flag=0;

void palindrome(string s,int l,int u)
{
	if(l>=u)
	{
		flag=1;
		return;
	}
	if(s[l]==s[u])
		 palindrome(s,l+1,u-1);
	else
	{ 
		flag=-1;
		return;
	}
}
int main()
{
	cout<<"Eneter the string";
	string s;
	cin>>s;
    palindrome(s,0,s.length()-1);
	if(flag==1)
		cout<<endl<<s<<" is an palindrome"<<endl;
	else
		cout<<endl<<s<<" is NOT a Palindrome"<<endl;
	return 0;
}