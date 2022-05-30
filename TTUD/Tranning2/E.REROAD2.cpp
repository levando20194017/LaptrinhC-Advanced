#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int arr[N];
	for(int i=1; i<=N; i++)	cin>>arr[i];
	int numberNot;
	cin>>numberNot;
	int doanDuong, lopNhuaMoi;
	while(numberNot--){
		int count = 1;
		cin>>doanDuong>>lopNhuaMoi;
		arr[doanDuong] = lopNhuaMoi;
		for(int i=1; i<N; i++){
			if(arr[i+1]!=arr[i]) count ++;
		}
		cout<<count<<endl;
	}
	return 0;
}
