#include<iostream>
using namespace std;
const int N = 1e4 +7;
int n;
int x[N];
int TRY(int k){
	if(k==0) return 0;
	if(x[k] == 0){
		x[k] = 1;
		for(int i=k+1; i<=n; i++){
			x[i] = 0;
		}
		return 1;
	}
	else TRY(k-1);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	string s;
	cin>>s;
	for(int i=n; i>=1; i--){
		x[i] = s[i-1] - '0';
	}
	if(TRY(n)){
		for(int i=1; i<=n; i++){
			cout<<x[i];
		}
	}
	else cout<<-1;
	return 0;
}
