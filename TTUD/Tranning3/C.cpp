#include<iostream>
using namespace std;
const int M = 11;
const int N = 31;
int m,n;
int a[N][N];
int k;
int maximal_load;

int main(){
	cin>>m>>n;
	for(int i=1; i<=m; i++){
		int n_specialize;
		cin>>n_specialize;
		for(int j=1; j<=n_specialize; j++){
			cin>>a[i][j];
		}
	}
	cin>>k;
	vector<int> a[k];
	for(int i=1; i<=k; i++){
		int u, v;
		cin>>u>>v;
		a[u].push_back(v);
	}
	return 0;
}
