#include<iostream>
using namespace std;
int main(){
int n,b;
int rs = -1;
cin>>n>>b;
int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int maxL[n], maxR[n];
	maxL[0] = arr[0];
	maxR[n-1] = arr[n-1];
	for(int i=0; i<n-1; i++){
		maxL[i+1] = max(arr[i+1], maxL[i]);
	}
	for(int i=n-2; i>=0; i--){
		maxR[i] = max(arr[i], maxR[i+1]);
	}
	for(int i=0; i<n-1; i++){
		if(maxL[i] - arr[i+1] >= b && maxR[i] - arr[i+1] >=b) rs = max(rs, maxL[i] + maxR[i] - 2*arr[i+1]);
	}
	cout<<rs;
	return 0;
}
