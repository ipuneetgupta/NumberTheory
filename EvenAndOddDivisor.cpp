// EvenAndOddDivisor
#include<iostream>
using namespace std;
#define ll long
void No_of_Div(ll *arr,ll n){
	int cnt=0;
  for(int i=1;i*i<=n;i++){
      if(n%i==0){
        arr[cnt++]=i;
        if(i!=n/i)
        arr[cnt++]=n/i;
      }
   }	
}
int main(){
  ll q;
  cin>>q;
  while(q--){
   ll arr[10005]={0};
   ll n;
   ll sum=0;
   cin>>n;
   No_of_Div(arr,n);
  //for(int i=0;i<100;i++) cout<<arr[i]<<" ";
   for(int i=0;i<n;i++){
       if(arr[i]!=0){
           if(arr[i]%2==0) sum+=arr[i];
           else sum-=arr[i];
       }else break;
   }
   cout<<sum<<endl;
  }
	return 0;
}