#include<iostream>
using namespace std;
const int MAX = 30;
int x[MAX];
int N,K,S;
int sum;
int a[MAX];
int count;
bool check(int v, int k){
    if(k < K) return 1;
    return sum + v == S;
}
int TRY(int k){
	for(int v = x[k-1] +1 ; v <= N ; v++){
        if(check(a[v],k)){
            x[k] = v;
            sum += a[v];
            if(k == K) count++;
            else TRY(k+1);
            sum -= a[v];
        }
    }
    return count;
}
int main(){
	cin>>N>>K>>S;
	for(int i=1; i<=N; i++){
		cin>>a[i];
	}
	//TRY(1);
	cout<<TRY(1);
	return 0;
}
