#include<iostream>
using namespace std;
int mem[1000];
int fibo(int n){
	if(n<=2) return 1;
	else return (fibo(n-1)+ fibo(n-2));
}
int fibo2(int n){
	if(n<=2)	 return 1;
	if(mem[n]!= 0) return mem[n];
	int res= fibo2(n-1)+ fibo2(n-2);
	mem[n]= res;
	return res;
}
int main(){
//	for(int i=0; i<1000; i++){
//		mem[i]=-1;
//	}
	cout<<fibo2(50);
	return 0;
}
