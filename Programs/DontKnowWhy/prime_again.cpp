#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
#define ll long long
ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
/* 
 * modular exponentiation
 */
ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
 
/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool Miller(ll p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{ 
	
    int t;
    cin>>t;
	while(t--)
	{
       
		unsigned long int a;
        unsigned long int i=0;
		cin>>a;
		if(a==3)
			cout<<2<<endl;
		else if(a==5||a==4)
			cout<<3<<endl;
		else if(a==7)
			cout<<5<<endl;
		else if(a==11)
			cout<<7<<endl;
       
       else 
       {
       i=a-1;
        while(true)
        {
            if(i%6==1||i%6==5)
                {
                    if(Miller(i,2))
                    {
                        cout<<i<<endl;
                        break;
                    }
                }
            i--;
            continue;
        }
    }

}
	return 0;
}

