#include<iostream>
using namespace std;
int main(){
	int n;
//	int maxS[n];
	int arr[n];
	do{
	cin>>n;
	if(n>0){
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	int max = arr[1];
	for(int i=1; i<=n; i++){
		if(arr[i] != 0){
		int count = 1;
		for(int j=i+1; j<=n; j++){
			if(arr[j]>=arr[i]) count ++;
			else break;
		}
		for(int j=i-1; j>=1; j--){
			if(arr[j] >= arr[i]) count ++;
			else break;
		}
		max = max > (count*arr[i]) ? max : (count*arr[i]);
		}
	}
	cout<<max<<endl;
	}
	}while(n>0);
	return 0;
}
