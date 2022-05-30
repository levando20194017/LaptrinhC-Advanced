#include<iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int arr[N];
	for(int i=1; i<=N; i++)	cin>>arr[i];
	int count = 1;
	for(int i=1; i<N; i++){
			if(arr[i+1]!=arr[i]) count ++;
		}
	long long numberNot;
	cin>>numberNot;
	int doanDuong, lopNhuaMoi;
	while(numberNot--){
		cin>>doanDuong>>lopNhuaMoi;
		if(arr[doanDuong] == lopNhuaMoi) cout << count<<endl;
		else{
		int t = arr[doanDuong];
		arr[doanDuong] = lopNhuaMoi;
		if(doanDuong<=N-1&&doanDuong>=2){
		if(t==arr[doanDuong-1]){
			if(t==arr[doanDuong+1]){
				count += 2;
				cout<<count<<endl;
			}else{
				if(arr[doanDuong] == arr[doanDuong+1]) cout<<count<<endl;
				else	cout<<++count<<endl;
			}
		}else{
			if(t==arr[doanDuong+1]){
				if(arr[doanDuong-1] == arr[doanDuong]) cout<<count<<endl;
				else	cout<<++count<<endl;
			}else{
				if(arr[doanDuong-1] == arr[doanDuong+1]){
					if(arr[doanDuong] == arr[doanDuong-1]){
						count -= 2;
						cout<<count<<endl;
					}else cout<<count<<endl;
				}else{
					if(arr[doanDuong-1] == arr[doanDuong] || arr[doanDuong] == arr[doanDuong+1]) cout<<--count<<endl;
					if(arr[doanDuong-1] != arr[doanDuong] && arr[doanDuong] != arr[doanDuong+1]) cout<<count<<endl;
				}
			}
		}
		}
		if(doanDuong == 1){
			if(t==arr[2]) cout<<++count<<endl;
			else{
			if(arr[1] != arr[2]) cout<<count<<endl;
			if(arr[1] == arr[2]) cout<<--count<<endl;
			}
		}
		if(doanDuong == N){
			if(t==arr[N-1]) cout<<++count<<endl;
			else{
			if(arr[N] == arr[N-1]) cout<<--count<<endl;
			if(arr[N] != arr[N-1]) cout<<count<<endl;
			}
		}
		}
	}
	return 0;
}
