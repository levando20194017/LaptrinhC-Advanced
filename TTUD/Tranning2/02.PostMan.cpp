#include<iostream>
#include<math.h>
using namespace std;
int s1 = 0;
int s2 = 0;
int s = 0;
int sodu(int *m, int *v, int *x, int n, int k){
	int solan;
		for(int i=1; i<=n; i++){
		if(m[i] > k){
			solan = m[i] / k;
			s = s + 2*(x[i])*solan;
			m[i] = m[i]%k;
			if(m[i] == 0) v[i] = true;
		}
	}
	return s;
}
int Try(int j, int n, int *v, int *m, int *x, int k){
	if(v[n] == 0){
	int weight=0;
	for(int i=n; i>=j; i--){
		if(weight + m[i] <= k && m[i]>0){
			weight += m[i];
			v[i] = true;
		}
	}
	s1 += 2*x[n];
	}
	if(n == j) return s1;
	else Try(j, n-1, v, m, x, k);
}
int Try2(int n, int j, int *v, int *m, int *x, int k){
	if(v[n] == 0){
	int weight=0;
	for(int i=n; i<j; i++){
		if(weight + m[i] <= k){
			weight += m[i];
			v[i] = true;
		}
	}
	s2 += 2 * (x[n]);
	}
	if(n == j) return s2;
	else Try2(n+1, j, v, m, x, k);
}
int mid(int *x, int n){
	int i;
	for(i=1; i<=n; i++){
		if(x[i] >= 0) break;
	}
	return i;
}
int main(){
	int n, k;
	int x[n], m[n];
	cin>>n>>k;
	int v[n];
	for(int i=1; i<=n; i++){
		v[i] = 0;
	}
	for(int i=1; i<=n; i++){
		cin>>x[i]>>m[i];
	}	
	int h = sodu(m,v,x,n,k);
//	for(int i=1; i<=n; i++){
//		cout<<x[i]<<" "<<m[i]<<" "<<v[i]<<endl;
//	}
	h += Try(mid(x,n), n, v, m, x, k) + Try2(1, mid(x,n), v, m, x, k);
	cout<<h;
	return 0;
}
