#include<iostream>
using namespace std;
int mem[1000][1000];
int C(int k, int n){
	if(k==0||k==n) mem[k][n]=1;
	if(mem[k][n]<=0)
	mem[k][n] = C(k-1, n-1) + C(k, n-1);
	return mem[k][n];
}
int main(){
	cout<< C(3,5);
	return 0;
}
