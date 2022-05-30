#include<bits/stdc++.h>

using namespace std;

#define MAX 510 
int n, k;
int x[MAX], y[MAX];
vector<bool> visit(MAX, false);
struct STR{
	int u, v;
	int w;
	STR(int _u, int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}
	
};
vector<vector<STR> > Adj(MAX);
void input(){
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		cin>>x[i]>>y[i];
	}
}
vector<int> Dijkstra(int start){
	vector<int> vec(n+1, LONG_MAX);
	vec[start] = 0;
	priority_queue <pair <int , int>,
	                vector <pair <int , int >>,
                    greater <pair <int , int >>> P;
    P.push(make_pair(vec[start], start));
    while(!P.empty()){
    	int u = P.top().second;
    	P.pop();
    	for(STR e: Adj[u]){
    		int v = e.v;
    		int w = e.w;
    		if(vec[v] > w + vec[u]){
    			vec[v] = w + vec[u];
    			P.push(make_pair(vec[v], v));
			}
		}
	}
	
	
	return vec;
}
void Solve(){
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= n; j++){
			int d = sqrt( (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i]-y[j]));
			if(d <= k){
				Adj[i].push_back(STR(i, j, d));
				Adj[j].push_back(STR(j, i, d));
			}
		}
	}
	vector<int> res = Dijkstra(1);
	if(res[n] < LONG_MAX) cout<<res[n];
	else cout<<-1;
}


int main(){
	ios_base::sync_with_stdio(false);
	//
    cin.tie(0); cout.tie(0);
    input();
    Solve();
    return 0;
}
