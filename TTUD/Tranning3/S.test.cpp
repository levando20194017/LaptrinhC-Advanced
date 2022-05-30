#include<iostream>
using namespace std;
const int N = 1e4 +7;
int n, i;
int x[N];
int count = 0;
unsigned long long k;
int sum;
 
void solution(){
	count++;
	if(count == k){
		for(int o=1; o<=n; o++)
			cout<<x[o]<<" ";
	}
}
void TRY(int l){
	for(int v= 0; v<=1; v++){
		if(count<k && (sum <= i-2 || (sum == i-1 && v== 1))){
			x[l] = v;
			if(v == 0) sum++;
			else sum = 0;
			if(l==n)
				solution();
			else TRY(l+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>k>>i;
	TRY(1);
	if(count != k) cout << "-1";
	return 0;
}
