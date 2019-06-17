
///Boston Number

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   int Sum_Digit=0;
   int temp=n;
    int sm_pm=0;
   //sum of dig
   while(temp>0){
       Sum_Digit+=temp%10;
       temp/=10;
   }
//sum of digit of prime factor
   for(int i=2;i*i<=n;i++){
   	 if(n%i==0){
   	 	 int cnt=0;
   	 	 while(n%i==0){
   	 	 	n=n/i;
   	 	 	cnt++;
   	 	 }
   	 	 //calculate the sum
   	 	 int tmp=i;
   	 	 int sm=0;
   	 	 while(tmp>0){
   	 	 	sm+=tmp%10;
   	 	 	tmp/=10;
   	 	 }
   	 	 sm_pm+=sm*cnt;
   	 }
   	}
   	 if(n>1){
       int tmp=n;
       while(tmp>0){
       	sm_pm+=tmp%10;
       	tmp/=10;
       }
   	 }
   
   cout<<(Sum_Digit==sm_pm)<<endl;
}