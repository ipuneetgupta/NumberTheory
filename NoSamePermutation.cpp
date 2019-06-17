// NoSamePermutation
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
bool check(vector<int> &arr,int s,int curr){
	for(int i=s;i<curr;i++){
		if(arr[i]==arr[curr]) return 0;
	}
	return 1;
}
void Distint_Permutation(vector<int> &arr,int idx,int n){
 //base case
	if(idx==n){
		// for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		ans.push_back(arr);
		return;
	}
 //find premutaion
	for(int i=idx;i<n;i++){
		if(check(arr,idx,i)){
			swap(arr[idx],arr[i]);
			Distint_Permutation(arr,idx+1,n);
			swap(arr[idx],arr[i]);
		}
	}
	return;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
   // sort(arr.begin(),arr.end());
    Distint_Permutation(arr,0,n);
    sort(ans.begin(),ans.end());
    for(vector<vector<int> > :: iterator i=ans.begin();i!=ans.end();i++){
    	for(int j=0;j<(*i).size();j++){
    		cout<<(*i).at(j)<<" ";
    	}
    	cout<<endl;
    }
}