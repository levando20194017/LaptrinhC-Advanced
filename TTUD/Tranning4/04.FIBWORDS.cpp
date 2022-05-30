#include<bits/stdc++.h>
using namespace std;
const int MAX = 110;
string s;
string p;
int n;
int count;
string Member[MAX];
string Fibo(int n){
	if(n==0) Member[0] = "0";
	if(n==1) Member[1] = "1";
	if(Member[n].length() == 0) Member[n] = Fibo(n-1) + Fibo(n-2);
	return Member[n];
}
void dem(string s, string p){

}
int main(){
	cin>>n>>p;
	s = Fibo(n);
	cout<<s;
	return 0;
}
