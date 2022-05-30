#include<iostream>
#include<math.h>
using namespace std;
const int N = 501;
int k;
int n;
int C[N][2];
int count = 1;
int visited[N];
int x[N];
int MAX;
int dmin;
int MIN = 10000000;
int d[N][N];
int KhoangCach(int u){
	d[x[u-1]][x[u]] = sqrt((C[u][2] - C[u-1][2])*(C[u][2] - C[u-1][2]) + (C[u-1][1] - C[u][1])*(C[u-1][1] - C[u][1]));
	return (int)d[x[u-1]][x[u]];
}

bool check(int v, int u){
	if(visited[v]) return false;
//	if(KhoangCach(v) > k) return false;
	return true;
}

void Try(int u){
	for(int v=2; v<=n; v++){
		if(check(v,u)){
			x[u] = v;
			if(KhoangCach(u) <= k){
			visited[v] = true;
			count++;
			dmin += KhoangCach(u);
			if(u==n && count == n){
				MAX =  max(count, MAX);
				MIN = min(MIN, dmin);
			}
			else{
				Try(u+1);
			}
			count-- ;
			dmin -= KhoangCach(u);
			visited[v] = false;
		}
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>C[i][1]>>C[i][2];
	}
	visited[1] = true;
	x[1] = 1;
	Try(2);
	if(MAX == n){
		cout<<MIN;
	}else cout << -1;
	return 0;
}
