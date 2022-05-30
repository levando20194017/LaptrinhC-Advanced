#include<iostream>
using namespace std;
const int N = 20;
const int M = 400;
int n,m;
int d[N][N];
int x[N];
int f;
int f_best = 1e6;
int visited[N];
int dm;
void updateBest(){
	if(f + d[x[n]][x[1]] < f_best){
		f_best = f +d[x[n]][x[1]];
	}
}
void Try(int k){
	for(int v=2; v<=n; v++){
		if(visited[v] == 0 && d[x[k-1]][v] != 0){
			x[k] = v;
			visited[v] = true;
			f = f + d[x[k-1]][x[k]];
			if(k==n){
				if(d[x[n]][x[1]] != 0)
				updateBest();
			}
			else{
				if(f + dm*(n-k+1) < f_best) Try(k+1);
			}
			visited[v] = false;
			f = f - d[x[k-1]][x[k]];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	dm = 1e6;
	for(int i=1; i<=m; i++){
		int k,j,c;
		cin>>k>>j>>c;
		d[k][j] = c;	
		if(dm > c) dm = c;
	}
	x[1] = 1;
	visited[1]  = true;
	Try(2);
	cout<<f_best;
	return 0;
}
