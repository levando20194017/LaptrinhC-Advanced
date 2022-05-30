#include<iostream>
using namespace std;
const int N = 1e4 +7;
int n, i;
int x[N];
int count = 0;
unsigned long long k;
int sum;

void solution(){
	for(int o=1; o<=n; o++){
		cout<<x[o]<<" ";
	}
	cout<<endl;
}
void TRY(int l){
	for(int v= 0; v<=1; v++){
		x[l] = v;
		if(l==n){
			solution();
		}
		else TRY(l+1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	TRY(1);
	return 0;
}
