#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
bool match(char a, char b){
	if(a=='(' && b==')') return true;
	if(a=='[' && b==']') return true;
	return false;
}
bool solve(string x, int n){
	stack<char> S;
	for(int i = 0; i <= n-1; i++){
		if(x[i] == '[' || x[i] == '('){
		S.push(x[i]);
	}else{
	if(S.empty()){
		return false;
		}else{
		char c = S.top(); S.pop();
		if(!match(c,x[i]))
		return false;
		}
	}
}
return S.empty();
}
int main() {
	string s;
	cin>>s;
	int MAX = 0;
	for(int i=0; i<s.length()-1; i++){
		for(int j=i+1; j<s.length(); j+2){
			string cc = s.substr(i, j-i+1);
			if(solve(cc, cc.length())){
				if(cc.length() > MAX){
					MAX = cc.length();
					cout<<cc;
				}
			}
			cc.erase(i, j-i+1);
		}
	}
return 0;
}
