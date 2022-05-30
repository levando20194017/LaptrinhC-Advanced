#include<iostream>
using namespace std;
int C(int k, int n){
	if(k==0 || k==n) return 1;
	return C(k-1, n-1) + C(k, n-1);
}
int main(){
	cout<<C(3,5);
	return 0;
}
