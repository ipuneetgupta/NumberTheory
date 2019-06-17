// 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int row=1,col=1;
	while(row<=n){
		col=1;
		//print s
		if(row==(n/2+1)||row==1||row==n){
		while(col<=n){
            cout<<"s"<<" ";
            col++;
		}
		cout<<endl;
		row++;
		continue;
	}
  //now print star
		if(row<(n/2+1)){
			while(col<=n){
              if(col==1) cout<<"s"<<" ";
              else cout<<"*"<<" ";
              col++;
			}
		}
		if(row>(n/2+1)){
            while(col<=n){
            	if(col==n) cout<<"s ";
            	else cout<<"*"<<" ";
            	col++;
            }
		}
		cout<<endl;
		row++;
	}
	return 0;
}