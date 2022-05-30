#include<iostream>
using namespace std;

const int MAX = 35;
int n,b;
int a[MAX], c[MAX];
int x[MAX];
int curVal, curW;
int ans;

bool check(int v, int k){
	return curW + a[v] <= b;
}
void Try(int k){
	for(int v= x[k-1]+1; v<=n; v++){
		if(check(v,k)){
			x[k] = v;
			curW += a[v];
			curVal += c[v];
			
			if(curVal > ans) ans = curVal;
			Try(k+1);
			curW -= a[v];
			curVal -= c[v];
		}
	}
}

int main(){
	cin>>n>>b;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
	}
	Try(1);
	cout<<ans;
	return 0;
}
