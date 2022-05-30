#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int max = pow(arr[0], 3);
	int s = pow(arr[0], 3);
	for(int i=1; i<n; i++){
		if(s > 0){
			s = s +pow(arr[i], 3);
		}else s = pow(arr[i], 3);
		max = s>max ? s:max;
	}
	cout<<max;
	return 0;
}
