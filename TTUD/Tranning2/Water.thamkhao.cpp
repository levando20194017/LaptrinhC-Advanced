#include<bits/stdc++.h>
using namespace std;
const int N = 910;
bool visited[N][N];
int d[N][N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	queue<pair<int, int>> q;
	q.push({0, 0});
	visited[0][0] = 1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x==c||y==c){
			cout<<d[x][y]<<endl;
			return 0;
		}
		//do nuoc vao a => (a,y)
		if(!visited[a][y]){
			visited[a][y] = 1;
			d[a][y] = d[x][y] + 1;
			q.push({a, y});
		}
		// do nuoc vao b => (x,b)
		if(!visited[x][b]){
			visited[x][b] = 1;
			d[x][b] = d[x][y] + 1;
			q.push({x, b});
		}
		//do nuoc tu a => (0,y)
		if(!visited[0][y]){
			visited[0][y] = 1;
			d[0][y] = d[x][y] + 1;
			q.push({0, y});
		}
		//do nuoc tu b =>(x, 0)
		if(!visited[x][0]){
			visited[x][0] = 1;
			d[x][0] = d[x][y] + 1;
			q.push({x, 0});
		}
		//do nuoc tu a vao b => (max(0, x+y-b) , min(b, x+y))
		if(!visited[max(0, x+y-b)][min(b, x+y)]){
			visited[max(0, x+y-b)][min(b, x+y)] = 1;
			d[max(0, x+y-b)][min(b, x+y)] = d[x][y] + 1;
			q.push({max(0, x+y-b) , min(b, x+y)});
		}
		//do nuoc tu b vao a ==> (min(a, x+y) , max(0, x+y-a))
		if(!visited[min(a, x+y)][max(0, x+y-a)]){
			visited[min(a, x+y)][max(0, x+y-a)] = 1;
			d[min(a, x+y)][max(0, x+y-a)] = d[x][y] + 1;
			q.push({min(a, x+y) , max(0, x+y-a)});
		}
	}
	cout<<-1;
	return 0;
}
