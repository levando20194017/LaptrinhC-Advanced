#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int res[2*N][2*N];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int L,C;
		cin>>L>>C;
		vector<pair<int , int>> a, b;
		for(int i=1; i<=L; i++){
			for(int j=1; j<=C; j++){
				int u;
				cin>>u;
				if(u==1) a.push_back({i,j});
			}
		}
		for(int i=1; i<=L; i++){
			for(int j=1; j<=C; j++){
				int u;
				cin>>u;
				if(u==1) b.push_back({i,j});
			}
		}
		for(pair<int, int> u : a){
			for(pair<int , int> v  : b){
				pair<int, int> w = {u.first - v.first, u.second - v.second};
				res[w.first + N][w.second + N] ++;
			}
		}
		int MAX = 0;
		for(int i=0; i<2*N; i++){
			for(int j=0; j<2*N; j++){
				MAX  = max(MAX, res[i][j]);
			}
		}
		cout<<MAX<<endl;
		for(pair<int, int> u : a){
			for(pair<int , int> v  : b){
				pair<int, int> w = {u.first - v.first, u.second - v.second};
				res[w.first + N][w.second + N] --;
			}
		}
	}
	return 0;
}
