// NoOfCoprimeUnderN

#include<iostream>
#include<bits/stdc++.h>
#include<iterator>
using namespace std;
#define ll long long
int primes[1000006]={0};
void Sieve(){

	for(ll i=2;i<1000006;i++){
       if(primes[i]==0){
       	for(ll j=2*i;j<1000006;j+=i){
       		if(primes[j]==0){
       			primes[j]=i;
       		}
       }
       primes[i]=i;
	}
}
}
int main(){
	ll t;
  cin>>t;
  Sieve();
  while(t--){
  	set<ll> prime;
  	ll n;
  	cin>>n;
  	ll temp=n;
  	ll ans=n;
  	while(primes[temp]!=0){
        prime.insert(primes[temp]);
        temp=temp/primes[temp];
  	}
  	set<ll> ::iterator it;
  	for(it=prime.begin();it!=prime.end();it++){
  		ans=(ans-(ans/(*it)));
  	}
  	cout<<ans<<endl;
  }
}

