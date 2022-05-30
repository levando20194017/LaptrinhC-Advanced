#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
bool match(char a, char b){
	if(a=='(' && b==')') return true;
	if(a=='{' && b=='}') return true;
	if(a=='[' && b==']') return true;
	return false;
}
bool solve(char* x, int n){
	stack<char> S;
	for(int i = 0; i <= n-1; i++){
		if(x[i] == '[' || x[i] == '(' || x[i] == '{'){
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
	int n;
	cin>>n;
	while(n--){
	string s;
	cin>>s;
	char *cmp = const_cast<char*>(s.c_str());
	cout<<solve(cmp, s.length())<<endl;
	}
return 0;
}
