#include<iostream>
using namespace std;
const int N = 20;
const int M = 400;
int n,m;
int c[N][N];
int a[N];
int f;
int f_min;
int marked[N];
int cmin;
void process() {
 if(f + c[a[n]][a[1]] < f_min){
 f_min = f + c[a[n]][a[1]];
 } 
}
void TRY(int k){
	 for(int v = 1; v <= n; v++){
	 if(marked[v] == false){
		 a[k] = v;
		 f = f + c[a[k-1]][a[k]];
		 marked[v] = true;
		 if(k == n){
		 process();
		 }else{
		 int g = f + cmin*(n-k+1);
		 if(g < f_min) 
			TRY(k+1);
		 }
		 marked[v] = false;
		 f = f - c[a[k-1]][a[k]];
		 }
	 }
}

int main() {
 f_min = 9999999999;
 	cin>>n>>m;
	cmin = 1e9;
	for(int i=1; i<=m; i++){
	int k,j,d;
	cin>>k>>j>>d;
	c[k][j] = d;	
	if(cmin > d) cmin = d;
	}
for(int v = 1; v <= n; v++) 
 marked[v] = false;
 a[1] = 1; marked[1] = true;
TRY(2); 
return 0;
}
