// Direction.cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	char ch;
	int x=0,y=0;
  ch=cin.get();//this function ignore whitespace
  while(ch!='\n'){
  	if(ch=='N') y++;
  	else if(ch=='S') y--;
  	else if(ch=='E') x++;
  	else x--;
  	ch=cin.get();
  }
  cout<<x<<y;
  //first quadrant
  if(x>=0&&y>=0){
  	for(int i=0;i<x;i++) cout<<'E';
  		for(int i=0;i<y;i++) cout<<'N';
  	}
  //second quadrant
  else if(x<=0&&y>=0){
  	x=-1*x;
  	for(int i=0;i<y;i++) cout<<'N';
  		for(int i=0;i<x;i++) cout<<'W';
  	}
  else if(x<=0&&y<=0){
  	for(int i=0;i<abs(y);i++) cout<<'S';
  		for(int i=0;i<abs(x);i++) cout<<'W';
  	}
  else if(x>=0&&y<=0){
  	for(int i=0;i<x;i++) cout<<'E';
  		for(int i=0;i<abs(y);i++) cout<<'S';
  	}
}