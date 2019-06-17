
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int board[30][30];
bool isValidPosition(int row,int col,int n){
  return row>=0&&col>=0&&row<n&&col<n;
}
bool canPlace1(int row,int col,int n){
   int DirRow[] = {+2, +1, -1, -2, -2, -1, +1, +2};
   int DirCol[] = {+1, +2, +2, +1, -1, -2, -2, -1};
   for(int dir=0;dir<9;dir++){
      int nxtRow=row+DirRow[dir];
      int nxtCol=col+DirCol[dir];
      if(isValidPosition(nxtRow,nxtCol,n)&&board[nxtRow][nxtCol]){
            return false;
      }else{
          return true;
      }
   }
        
}
//more accurate to check every postion or canplace1 function if u put value acc
//this function it may become right
bool canPlace(int row,int col,int n){
     if (isValidPosition(row - 2, col - 1, n) && board[row - 2][col - 1]) {
            return false;
        } else if (isValidPosition(row - 2, col + 1, n) && board[row - 2][col + 1]) {
            return false;
        } else if (isValidPosition(row - 1, col - 2, n) && board[row - 1][col - 2]) {
            return false;
        } else if (isValidPosition(row - 1, col + 2, n) && board[row - 1][col + 2]) {
            return false;
        } else if (isValidPosition(row + 1, col - 2, n) && board[row + 1][col - 2]) {
            return false;
        } else if (isValidPosition(row + 1, col + 2, n) && board[row + 1][col + 2]) {
            return false;
        } else if (isValidPosition(row + 2, col - 1, n) && board[row + 2][col - 1]) {
            return false;
        } else if (isValidPosition(row + 2, col + 1, n) && board[row + 2][col + 1]) {
            return false;
        }

        return true;
}
 void PrintKnight(int Placed,int sr,int sc,int n,string res){
   if(Placed==n){
       cout<<res<<" ";
       cnt++;
       return;
   }
    for(int row=sr;row<n;row++){
      for(int col=(row==sr?sc:0);col<n;col++){
        if(board[row][col]==0&&canPlace(row,col,n)){
            board[row][col]=1;
           string ros="{"+to_string(row)+"-"+to_string(col)+"} ";
            PrintKnight(Placed+1,row,col+1,n,res+ros);
            board[row][col]=0;
        }
      }
    }
    return;
 }
using namespace std;
int main(){
  int n;
  cin>>n;
  PrintKnight(0,0,0,n," ");
  cout<<endl;
  cout<<cnt;
}