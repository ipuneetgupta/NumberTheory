
#include <iostream>
#include<vector>
using namespace std;
#define ll long long
int main()
{
    vector<bool> isprime(1001,false);
    vector<int> prime;
    for(int i=2;i<1001;i++)
    {
    	if(!isprime[i])
    	{
    		prime.push_back(i);
    		//cout<<i<<"  ";
    		for(int j=i+i;j<1001;j+=i)
    			isprime[j]=true;
    	}   	
    }
    int n;
    cin>>n;
    if(n==1||n==0)
    	cout<<"0"<<endl;
    else if(n==2)
    	cout<<"1"<<endl;
    else 
    {
    	ll p=1,res=1;
    	
    	for(int i=3;i<=n;i++)
    	{	if(!isprime[i])
    		{
    		p*=2;
    	//a	cout<<i<<p<<endl;
    		}
    		res+=p;
    		
    	}	
    	cout<<res<<"\n";
    }
    	
    return 0;
}
