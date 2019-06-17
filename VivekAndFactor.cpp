// VivekAndFactor
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll No_Sum_Divisor(ll n){
    ll sum=0;
    if(n==1){ return 1;}
  for(ll i=1;i*i<=n;i++){
        if(n%i==0){
        	if(n/i!=i){
        		sum+=i+n/i;
        	}else{
        		sum+=i;
        	}
        }
  }
  return sum;
}
int main(){
  ll s;
  cin>>s;
  while(s!=0){
  	ll i;
  	for( i=1;i<s;i++){
          if(No_Sum_Divisor(i)==s){
          	cout<<i<<endl;
          	break;
          }
  	}
  	if(i==1)cout<<1<<endl;
  	if(i==s&&i!=1) cout<<-1<<endl;
  	cin>>s;
  }
}