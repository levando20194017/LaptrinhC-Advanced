#include<iostream>
using namespace std;
const int  MAX = 1e5 + 5;
int N, L1, L2;
int a[MAX];
int F[MAX];
int best;

void input(){
	cin>>N>>L1>>L2;
	for(int i=1; i<=N; i++){
		cin>>a[i];
	}
}
void solve(){
	for(int i=1; i<=N; i++){
		F[i] = a[i];
		int tmp = 0;
		for(int j=L1; j<=L2; j++){
			if(i-j>0 && tmp<F[i-j]){
				tmp = F[i-j];
			}
		}
		F[i] += tmp;
		best = max(best, F[i]);
	}
}
int main(){
	
	return 0;
}
