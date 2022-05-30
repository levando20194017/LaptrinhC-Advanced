#include<iostream>
using namespace std;
const int MAX = 35;

int H,W,N;
int h[MAX], w[MAX];

int b[MAX][MAX];
int x[MAX], y[MAX];
int ans;

void mark(int vx, int vy, int k, int val){
	for(int i=vx; i<=vx+w[k]-1; i++){
		for(int j=vy; j<=vy+h[k]-1; j++){
			b[i][j] = val;
		}
	}
}
bool check(int vx, int vy, int k){
	for(int i=vx; i<=vx+w[k]-1; i++){
	for(int j=vy; j<=vy+h[k]-1; j++){
		if(b[i][j] == 1) return false;
		}
	}
	return true;
}
void TRY(int k){
	if(ans == 1) return;
	for(int vx = 0; vx<= W - w[k]; vx++){
		for(int vy = 0; vy <= H - h[k]; vy++){
			if(check(vx, vy, k)){
				mark(vx, vy, k, 1);
				if(k==N) ans = 1;
				else TRY(k+1);
				mark(vx, vy, k, 0);
			}
		}
	}
}

int main(){
	cin>>H>>W;
	cin>>N;
	for(int i=1; i<=N; i++){
		cin>>h[i]>>w[i];
	}
	TRY(1);
	cout<<ans;
	return 0;
}
