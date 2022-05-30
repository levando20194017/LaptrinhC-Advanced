#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(arr[i].length() > 10){
		string s = to_string(arr[i].length() - 2);
		arr[i].erase(arr[i].begin() + 1, arr[i].end()-1);
		arr[i].insert(1 , s);
		}
	}
	for(int i=0; i<n; i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}
