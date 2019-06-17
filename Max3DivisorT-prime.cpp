// Max3DivisorT-prime

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> prime;
set<ll> chk;
void Precompute_prime(){
    prime.push_back(2);
    chk.insert(2);
  for(ll i=3;i<100007;i+=2){
  	bool flag=true;
      ll stp=sqrt(i)+1;
  	for(vector<ll> :: iterator it=prime.begin();it!=prime.end();it++){
  		if((*it)>=stp) break;
  		if(i%(*it)==0) {
              flag = false;
               break;
          }
  	}
  	if(flag==true) {
  	    prime.push_back(i);
  	    chk.insert(i);
  	}
  }
  return ;
}
//calculate no of divisor
ll No_Of_Divisor(ll n){
	ll Total_Cnt=1;
	vector<ll> :: iterator it=prime.begin();
   while(*it<=n&&(it!=prime.end())){
   	           ll cnt=0;
   	          if(n<=0) break;
            while(n%(*it)==0&&n>0){
            	n=n/(*it);
            	cnt++;
            }
            Total_Cnt=Total_Cnt*(cnt+1);
            //if(Total_Cnt>3) return 0;
        it++;
   }
   return Total_Cnt;
}
int main(){
  Precompute_prime();
  ll n;
  cin>>n;
  while(n--){
  	ll x;
  	cin>>x;
  	//int no=No_Of_Divisor(x);
  	double sqr=sqrt(x);
  	if(x==4) cout<<"YES"<<endl;
  	else if(x%2==0) cout<<"NO"<<endl;
  	else if((sqr==int(sqrt(x)))&&(chk.find(int(sqrt(x)))!=chk.end())) cout<<"YES"<<endl;
  	else cout<<"NO"<<endl;
  }
  // for(vector<ll>:: iterator it=prime.begin();it!=prime.end();it++){
  //     cout<<*it<<endl;
  // }
}