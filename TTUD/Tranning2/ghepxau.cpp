#include<iostream>
#include<string>
using namespace std;
string ghepXau(int n){
	if(n==1) return "A";
	if(n==2) return "B";
	return ghepXau(n-1) + ghepXau(n-2);
}
int main(){
	string c = ghepXau(10);
	cout<<c;
	return 0;
}
