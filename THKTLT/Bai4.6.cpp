#include<bits/stdc++.h>
using namespace std;
void bfs(vector< list<int> > adj){
	vector<bool> visited (adj.size(), false);
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()){
		int u = Q.front();
		visited[u] = true;
		cout<<u<<endl;
		Q.pop();
		for(int i= 0; i< adj[u].size(); i++){
			int v = adj[u].front();
			adj[u].pop_front();
			i--;
			if(!visited[v]){
			visited[v] = true;
			 Q.push(v);
		}
		}
}
}
int main(){
	cout<<"Le Van Do 20194017";
int n = 10;
vector< list<int> > adj;
adj.resize(n + 1);
adj[1].push_back(2);
adj[1].push_back(3);
adj[1].push_back(6);
adj[2].push_back(7);
adj[2].push_back(4);
adj[2].push_back(8);
adj[3].push_back(10);
adj[3].push_back(9);
adj[4].push_back(1);
adj[4].push_back(8);
adj[5].push_back(2);
adj[5].push_back(4);
adj[6].push_back(7);
adj[6].push_back(9);
adj[7].push_back(3);
adj[7].push_back(9);
adj[7].push_back(10);
adj[8].push_back(9);
adj[8].push_back(2);
adj[9].push_back(3);
bfs(adj);
}
