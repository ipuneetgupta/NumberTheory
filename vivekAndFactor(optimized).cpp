// vivekAndFactor(optimized)
#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;
#define ll long long
vector<int> primes;
map<int,int> Div_sum;
ll power(ll a,ll b){
	ll ans=1;
	if(b==1) return a;
	while(b>0){
		if(b&1){
			ans=ans*a;
		}
		a=a*a;
		b=b>>1;
	}   
	return ans; 
}
void precompute(){
	primes.push_back(2);
	bool flag=true;
	for(int i=3;i<100005;i++){
		flag=true;
		int stp=sqrt(i)+1;
		for(vector<int> ::iterator it=primes.begin();it!=primes.end();it++){
			if((*it)>stp) break;
			if(i%(*it)==0){
				flag=false;
				break;
			}
		}
		if(flag) primes.push_back(i);
	}
	return;
}
void Divisor_Sum_precompute(){

	Div_sum[1]=1;
	for(int i=2;i<=100000;i++){
		int tmp=i;
  	map<int,int> prm_pow;//store the prime no power of i 
  	vector<int> :: iterator it=primes.begin();
  	int cnt=0;
  	while(it!=primes.end()){
  		if(tmp%(*it)==0){
  			tmp/=(*it);
  			cnt++;
  		}else {
  			if(cnt!=0)
  				prm_pow[*it]=cnt;
  			if(tmp<=1) break;
  			cnt=0;
  			it++;
  		}
  	}
  	// map<int ,int> :: iterator it2=prm_pow.begin();
  	// for(;it2!=prm_pow.end();it2++) cout<<it2->first<<" "<<it2->second<<endl;
  		long long ans=1;
  	map<int ,int> :: iterator it1=prm_pow.begin();
  	for(;it1!=prm_pow.end();it1++){
  		int p=it1->first;
  		int e=it1->second;
  		ans=ans*(power(p,e+1)-1)/(p-1);
  	}
  	Div_sum[ans]=i;
  }
  return ;
}
int main(){
	precompute();
	Divisor_Sum_precompute();
	// map<int,int>:: iterator it=Div_sum.begin();
	// for(;it!=Div_sum.end();it++){
	// 	cout<<it->first<<" "<<it->second<<endl;
	// }
	ll s;
	cin>>s;
	while(s!=0){
		map<int,int> ::iterator it=Div_sum.find(s);
		if(it!=Div_sum.end()){
			cout<<it->second<<endl;
		} else cout<<-1<<endl;
		cin>>s;
	}
}