#include<iostream>
using namespace std;
const int N  = 1000010;
int n;
int arr[N];
void quikSort(int a[], int l, int r){
	if( l==r ) return;
	int count = 0;
	for(int i=l; i<r; i++){
		if( a[l]>a[i] ) count++;
	}
	int tmp = a[l];
	a[l] = a[l+count];
	a[l+count] = tmp;
	for(int i=l; i<l+count; i++){
		for(int j=i; j<r; j++){
			if(a[j] < a[l+count]){
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			break;
			}
		}
	}
	quikSort(a, l, l+count);
	quikSort(a, l+count+1, r);
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	quikSort(arr, 0, n);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
