// PlayingDivisorIsFun
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<ll> primes;
//Precompute prime no
void Precompute(){
 primes.push_back(2);
 for(ll i=3;i<=1000006;i+=2){
 	vector<ll> :: iterator it;
    ll stp=sqrt(i)+1;
    bool flag=true;
    for(it=primes.begin();it!=primes.end();it++){
    	if(*it>=stp) break;
    	if(i%(*it)==0){
           flag=false;
           break;
    	}
    }
    if(flag) primes.push_back(i);
 }
 return;
}
//no of divisors
ll NO_Of_Div(ll n){
	ll Total_Cnt=1;
	vector<ll> ::iterator it=primes.begin();

	while(it!=primes.end()){
		 ll cnt=0;
		if(*it<=0) break;
		while(n%(*it)==0&&n>0){
           n=n/(*it);
           cnt++;
         }
         Total_Cnt=(Total_Cnt*(cnt+1))%mod;
        it++;
	}
	return Total_Cnt;
}
// fast Power exponentiation
ll power(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b&1){
          ans=ans*a;
          ans%=mod;
		}
		a=a*a;
		a%=mod;
		b=b>>1;
	}
	return ans;
}
//Inverse of No--modified euler theoram
ll Inverse_Euler(ll n){
   return power(n,mod-2);
}
//multiplication of divisors of n
ll Mul_Div_OfN(ll n){
	ll ans=1;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
         if(n/i==i) {
           ans=(ans*i)%mod;
         }
         else {
         	ans=(ans*i)%mod;
         	ans=(ans*Inverse_Euler(i))%mod;
         	ans=(ans*n)%mod;
         }
     }
	}
	return ans;
}
//calculate the prime power of n no.
ll PrimePower(ll *arr,ll n){
  vector<ll> ::iterator it=primes.begin();
  ll ans=1;
  for(int i=0;i<n&&it!=primes.end();i++,it++){
  	ll pp=power(*it,arr[i]);
       ans=(ans*pp)%mod;
  }
   return ans;
}
int main(){
	Precompute();
  ll n;
  cin>>n;
  ll arr[n];
  for(ll i=0;i<n;i++) cin>>arr[i];
  ll pp=PrimePower(arr,n);
  ll Mul=Mul_Div_OfN(pp);
  ll cnt=NO_Of_Div(Mul);
  cout<<cnt<<endl;
}