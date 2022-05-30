#include<iostream>
using namespace std;
const int N = 1e4 +7;
int n;
int k, count;
int x[N];
int visited[N];
void solution(){
	count++;
	if(count == k){
		for(int i=1; i<=n; i++){
		cout<<x[i]<<" ";
	}
	}
}
int TRY(int v){
	for(int u=1; u<=n; u++){
		if(!visited[u] && count<k){
			x[v] = u;
			visited[u] = true;
			if(v==n) solution();
			else TRY(v+1);
			visited[u] = false;
		}
	}
}
int main(){
	cin>>n>>k;
	TRY(1);
	if(count!=k) cout<<-1;
	return 0;
}
