#include<iostream>
using namespace std;
int n;
int X(int n);
int Y(int n);
int main(){
	cout<<X(6) + Y(6); 
	return 0;
}
int X(int n){
	if(n<=5){
	return n;
	}
	else return X(n-4) + X(n-2) + Y(n-3) + Y(n-1);
}
int Y(int n){
	if(n<=5) return 2*n;
	else return Y(n-4) + Y(n-2) + X(n-3) + X(n-1);
}

