#include<bits/stdc++.h>
using namespace std;
#define N 100
vector<int> A[N];
int t;
int n, m;
int d[N];
int f[N];
int p[N];
char color[N];
void input(){
	int u, v;
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		cin>>u>>v;
		A[u].push_back(v);
	}
	for(int i=1; i<=m; i++){
	sort(A[i].begin(), A[i].end());	
	}
}
void show(){
	for(int i=1; i<= n; i++){
		cout<<"A["<<i<<"]: ";
		for(int j=0; j< A[i].size(); j++) cout<<A[i][j]<<" ";
		cout<<endl;
	}
}
void DFS(int u){
	t++;
	d[u] = t;
	color[u] = 'G';
	for(int i=0; i<A[u].size(); i++){
		int v = A[u][i];
		if(color[v] == 'W'){
			p[v] == u;
			DFS(v);
		}
	}
	t++;
	f[u] = t;
	color[u] = 'B';
}
void DFS(){
	for(int i=1; i<=n; i++){
		color[i] = 'W';
	}
	for(int i=1; i<=n; i++){
		if(color[i] == 'W')
		DFS(i);
	}
	for(int v=1; v<=t; v++){
		for(int u=1; u<=n; u++){
			if(f[u] == v) cout<<u<<" ";
		}
	}
}
int main(){
	input();
	show();
	DFS();
	return 0;
}
