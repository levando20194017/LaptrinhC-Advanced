#include<iostream>
using namespace std;
const int N = 1e4+7;
int m,n,k;
int count;
int x[N];

void solution(){
	count++;
	if(count == k){
		for(int i=1; i<=m; i++) cout<<x[i]<<" ";
	}
}
void TRY(int v){
	for(int i= x[v-1] + 1; i<= n; i++){
		if(count<k){
			x[v] = i;
			if(v==m) solution();
			else TRY(v+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	x[0] = 0;
	TRY(1);
	if(count!=k) cout<<-1;
	return 0;
}
