// NthFibonaciiFast
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define matrix vector<vector<ll> >
matrix Multiply(matrix a,matrix b){
  matrix c (2,vector<ll>(2));
  for(int i=0;i<2;i++){
  	for(int j=0;j<2;j++){
  		for(int k=0;k<2;k++){
          c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%mod)%mod;
  		}
  	}
  }
  return c;
}
matrix power(matrix a, ll  p){
 if(p==1) return a;
 //if odd
 if(p&1){
 	return Multiply(a,power(a,p-1));
 }
 else{
 	matrix x=power(a,p/2);
 	return Multiply(x,x);
 }
}
int main(){
  matrix a (2,vector<ll>(2));
  a[0][0]=1,a[0][1]=1,a[1][0]=1,a[1][1]=0;
   ll t;
   cin>>t;
   while(t--){
   	ll n;
   	cin>>n;
   	if(n==0) cout<<0<<endl;
   	else{
   	  matrix b=power(a,n-1);
   	  cout<<b[0][0]<<endl;

   	}


   }

}