#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int max = arr[0];
	int s = arr[0];
	for(int i=2; i<n; i++){
		if(s > 0){
			s = s +arr[i];
		}else s = arr[i];
		max = s>max ? s:max;
		i += 1;
	}
	cout<<max;
	return 0;
}
