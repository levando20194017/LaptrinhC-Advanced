#include<bits/stdc++.h>
using namespace std;
const int N  = 1000010;
int l[N];
int r[N];
int a[N];
int main(){
	while(1){
		stack<int> st;
		int n;
		cin>>n;
		if(!n) break;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		for(int i=1; i<=n; i++){
			while(!st.empty() && a[st.top()]>=a[i]) st.pop();
			if(st.empty()) l[i] = 0;
			else l[i] = st.top();
			st.push(i);
		}
		while(!st.empty()) st.pop();
		for(int i=n; i>=1; i--){
			while(!st.empty() && a[st.top()]>=a[i]) st.pop();
			if(st.empty()) r[i] = n+1;
			else r[i] = st.top();
			st.push(i);
		}
		long long res = 0;
		for(int i=1; i<=n; i++){
			long long are = 1ll*a[i]*(r[i] - l[i] - 1);
			res = max(res, are);
		}
		cout<<res<<endl;
	}
	return 0;
}
