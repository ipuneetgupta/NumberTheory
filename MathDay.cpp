// MathDay(a^N!%p)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power(ll a,ll e,ll mod){
  if(e==0)return 1ll;
  if(a==0) return 0ll;

  ll pro=1;
  while(e>0){
    if(e&1)pro=(pro*a)%mod;
    a=(a*a)%mod;
    e=e/2;
  }
  return pro;
}
int main(){
	ll t;
	cin>>t;
	while(t--){
	ll a,n,p;
	cin>>a>>n>>p;
	ll ans=a;
	for(ll i=1;i<=n;i++){
        ans=power(ans,i,p);
	}
	cout<<(ans+p)%p<<endl;
}
}