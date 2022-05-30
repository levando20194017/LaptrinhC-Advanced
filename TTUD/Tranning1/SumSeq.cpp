#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	unsigned long long s = 0;
	const int dividend = pow(10, 9) + 7;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		s = s + arr[i] % dividend;
	}
	s = s % dividend;
	cout<<s;
	return 0;
}
