#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n,m;
int x[N];
int main(){
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		cin>>x[i];
	}
	int i;
	for(i=m; i>=1; i--){
	if(x[i] < n && i==m || x[i+1] - x[i] > 1){
		x[i] = x[i] + 1;
		break;
	}
	}
	if(i!=0){
		for(int j=1; j<=m; j++){
			cout<<x[j]<<" ";
		}
	}
	else cout<<-1;
	return 0;
}
