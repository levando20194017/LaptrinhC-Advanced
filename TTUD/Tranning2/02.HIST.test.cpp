#include<iostream>
using namespace std;
int main(){
	int n;
	do{
	cin>>n;
	int arr[n];
	int count[n];
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		count[i] = 1;
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(arr[j]>=arr[i]) count[i] ++;
			else break;
		}
		for(int j=i-1; j>=1; j--){
			if(arr[j] >= arr[i]) count[i] ++;
			else break;
		}
	}
	int *maxS = new int[n];
	for(int i=1; i<=n; i++){
		maxS[i] = arr[i] * count[i];
	}
	int max = maxS[1];
	for(int i=2; i<=n; i++){
	max = max > maxS[i] ? max : maxS[i];
	}
	cout<<max<<endl;
	}while(n>0);
	return 0;
}
