#include<iostream>
using namespace std;
int S= 0;
int SoCapByRecursive(int n){
	if(n<3) return 1;
	return SoCapByRecursive(n-1) + SoCapByRecursive(n-2);
}

int SoCap(int n){
	int H1 = 1, H2 = 1;
	for(int i=3; i<=n ; i++){
		S = H1 + H2;
		H1 = H2;
		H2 = S;
	}
	return S;
}
int main(){
	int n;
	cin>>n;
	cout<<SoCap(n);
	return 0;
}
