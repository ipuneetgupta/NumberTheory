// DuplicateCharacter
#include<iostream>
using namespace std;
string DuplicateStar(string str){
	//base case
	if(str.size()==0){
		return " ";
	}
	string ros= "";
	ros+=str[0];
	if(str[0]==str[1])ros+="*";
	ros+=DuplicateStar(str.substr(1));
	return ros;
}
int main(){
	string str;
	cin>>str;
    cout<<DuplicateStar(str);
}