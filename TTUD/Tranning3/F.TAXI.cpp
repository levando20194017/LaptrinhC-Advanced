#include<iostream>
using namespace std;
const int N = 11;
int n;
int d[2*N][2*N];
int x[2*N];
int f;
int f_best = 1e9;
int visited[2*N];
int dm;
int load;
bool check(int v, int u){
	if(visited[v]) return false;
	if(v<=n){
		if(load >= 1) return false;
	}else{
		if(!visited[v-n]) return false;
	}
	return true;
}
void updateBest(){
		if(f + d[x[2*n]][x[0]] < f_best){
		f_best = f +d[x[2*n]][x[0]];
	}
}
void Try(int u){
	for(int v=1; v<=2*n; v++){
		if(check(v,u)){
			x[u] = v;
			visited[v] = true;
			f = f + d[x[u-1]][x[u]];
			if(v<=n) load += 1;
			else load -= 1;
			if(u==2*n) updateBest();
			else{
				if(f + dm*(2*n-u+1) < f_best) Try(u+1);
			}
			visited[v] = false;
			f = f - d[x[u-1]][x[u]];
			if(v<=n) load -= 1; else load += 1;
		}
	}
}
int main(){
	cin>>n;
	dm = 1e9;
	for(int i=0; i<=2*n; i++){
		for(int j=0; j<=2*n; j++){
		cin>>d[i][j];
		if(i!=j && dm>d[i][j]) dm = d[i][j];
		}
	}
	Try(1);
	cout<<f_best;
	return 0;
}
