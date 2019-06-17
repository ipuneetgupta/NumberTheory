// PlayingDivisorFunOptimize
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
	ll n;
	cin>>n;
	ll arr[n];
	ll d=1;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
       d=(d*(arr[i]+1)+mod)%mod;
	}
	d/=2; //use multiplicatiivee inverse 
	ll ans=1;
	for(ll i=0;i<n;i++){
     ans=(ans*(((d*arr[i])+mod)%mod+1)+mod)%mod;
	}
	cout<<ans<<endl;
}