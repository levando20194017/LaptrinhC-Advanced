#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n;
bool visited[MAX];
vector<vector<int>> listNode;
int cnt = 0;
void input(){
	cin>>n;
	listNode.resize(n+1);
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		listNode[u].push_back(v);
		listNode[v].push_back(u);
	}
}
void solve(){
	queue<int> Q;
	Q.push(1);
	visited[1] = true;
	while(!Q.empty()){
		int v = Q.front(); Q.pop();
		for(int v1 : listNode[v]){
			if(!visited[v1]){
				Q.push(v1);
				visited[v1] = true;
			}	
		}
		int size_v = listNode[v].size();
		if(size_v == 1){
			cnt++;
		}
	}
	if(listNode[1].size() == 1) cnt--;
}
int main(){
	input();
	solve();
	cout<<cnt;
	return 0;
}
