// ChooseNumbers

#include<iostream>
using namespace std;
#define ll long
bool ChooseNumber(ll *arr,ll n){
	ll ans;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(arr[i]+arr[j]>=arr[k]) return true;
			}
		}
	}
	return false;
}
int main(){
  ll n;
  cin>>n;
  ll arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  	ChooseNumber(arr,n)==true?cout<<"YES":cout<<"NO";
}