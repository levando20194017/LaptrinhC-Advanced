#include<bits/stdc++.h>
using namespace std;
const int N  = 100;
int arr[N];
int n;
int count;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int i,j;
	for(i= 0; i<n; i++){
		if(arr[i]  == 0) break;
	}
	for(j=0; j<i; j++){
		if(arr[j] <0 ) break;
	}
	cout<<j+1<<" ";
	for(int k=0; k<=j; k++) cout<<arr[k]<<" ";
	cout<<endl<<i-j-1<<" ";
	for(int k=j+1; k<i; k++) cout<<arr[k]<<" ";
	cout<<endl<<(n-i)<<" ";
	for(int k=i; k<n; k++) cout<<arr[k]<<" ";
	return 0;
}
