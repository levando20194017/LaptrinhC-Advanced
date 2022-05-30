#include<bits/stdc++.h>
using namespace std;

const int MAX = 35;
int m,n;
vector<int> t[MAX]; //t[i] la danh sách giáo viên có thê day môn i
int x[MAX]; //x[i] la giao vien duoc phan công môn i
int load[MAX]; //load[i] so môn duoc phân công cho giáo viên i
bool c[MAX][MAX]; // c[i][j] là true nêu i j trùng thoi khoa bieu
int best; // ki luc
bool found; // found la true neu tim thay ket qua

bool check(int g, int k){
	for(int i=1; i<= k-1; i++){
		if(c[i][k] && x[i] == g) return false;
	}
	return true;
}
void solution(){
	found = true;
	int max_load = 0;
	for(int i=1; i<= m; i++) max_load = max(max_load, load[i]);
	best = min(best, max_load);
}
//bool cmp(int p, int  q){
//	return load[p] < load[q];
//}
//int get_ans(){
//	return *max_element(load+1, load + n+ 1);
//}
//void arrange(int i){
//	if
//}
void TRY(int k){// thu tung mon hoc
	for(int i=0; i<t[k].size(); i++){
		int g = t[k][i];
		if(check(g, k)){
			x[k] = g;
			load[g] ++;
			if(k==n) solution();
			else{
				if(load[g] < best) TRY(k+1);
			}
			load[g] --;
		}
	}
}

int main(){
	cin>>m>>n;
	for(int j=1; j<=m; j++){
		int q;
		cin>>q;
		while(q--){
			int p;
			cin>>p;
			t[j].push_back(p);
		}
	}
	int k;
	cin>>k;
	while(k--){
		int p1, q1;
		cin>>p1>>q1;
		c[p1][q1] = 1;
	}
	TRY(1);
	cout<<best;
	
	return 0;
}
