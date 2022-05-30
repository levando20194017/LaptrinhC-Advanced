#include<iostream>
using namespace std;
bool check(const string &name){
	if(name.length()<2) return true;
	else{
		if(name[0]!= name[name.length()-1]){
			return false;
		}
		string middle= name.substr(1,name.length()-2);
		return check(middle);
	}
}
int main(){
	cout<<check("llvll");
	return 0;
}
