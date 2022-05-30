#include<iostream>
using namespace std;
 
int dem=0;
int A[8][8]; 
int X[9] = { 0,  1, 1, 2, -1, -2, -1, 2, -2};
int Y[9] = { 0,  2, -2, -1, -2, -1, 2, 1, 1};
int n;

void xuat(){
	int s=1;
	do{
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(A[i][j]==s){
					cout<<"("<<i<<" "<<j<<")\n";
					break;
				}
			}
		}
		s++;
	}while(s<=n*n);
}

void dichuyen(int x, int y){
	++dem;
	A[x][y]=dem;
	for(int i=1; i<=9; i++){
		if(dem== n*n){
			xuat();
			exit(0);
		}
		int u = x + X[i];
		int v = y + Y[i];
		if(u>0 && v>0 && u <= n && v<=n && A[u][v]==0){
			dichuyen(u, v);
		}
	}
	--dem;
	A[x][y]=0;
}

int main(){
	cout<<"Le Van Do 20194017\n";
	scanf("%d", &n);
	dichuyen(1,1);
	return 0;
}
