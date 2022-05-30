#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, k;
vector<pair<int, int>> a,b;

long long solve(vector<pair<int, int>> &a){
	sort(a.begin(), a.end());
	long long res = 0;
	for(int i= a.size()-1; i>=0; i--){
		int num = (a[i].second + k -1)/k;
		res += 1ll*num*2*a[i].first;
		int h = num*k;
		for(int j=i; j>=0; j--){
			int need = min(h, a[j].second);
			a[j].second -= need;
			h -= need;
			if(h==0) break;
		}
	}
	return res;
}
int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		int m,l;
		cin>>m>>l;
		if(m>=0) a.push_back({m,l});
		else b.push_back({-m,l});
	}
	cout<<solve(a) + solve(b);
	return 0;
}
