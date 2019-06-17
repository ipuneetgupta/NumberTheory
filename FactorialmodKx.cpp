// FactorialmodKx
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll x=INT_MAX;
		ll cnt_k;
		//find possible pirme factor
		for(int i=2;i*i<=k;i++){
			if(k%i==0){
				//find occurence of prime factor i in k
				cnt_k=0;
				while(k%i==0){
					cnt_k++;
					k=k/i;
				}
				//find the occurence of pf in nfact
				ll cnt_nfact=0;
				ll tmp=i;
				while(tmp<=n){
				      cnt_nfact+=n/tmp;
				      tmp*=i;
				}
				x=min(x,cnt_nfact/cnt_k);
			}
		}
		//what if the k is not become zero it mean the prime factor is greater than k
		if(k>1){
          ll cnt_nfact=0;
          ll tmp=k;
          while(tmp<=n){
          	cnt_nfact+=n/tmp;
          	tmp*=k;
          }
          x=min(x,cnt_nfact);
		}
          if(x==INT_MAX) x=0;

          cout<<x<<endl;
	}
}