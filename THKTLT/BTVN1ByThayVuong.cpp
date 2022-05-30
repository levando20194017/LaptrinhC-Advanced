#include<iostream>
using namespace std;

int s=0;
int n;

//int H(int n){
//	if(n>=1 && n<=4) return n;
//	else return H(n-4) + H(n-3) -H(n-2) + H(n-1);
//}

//int Sum(int n){
//	for(int i=1; i<=n; i++){
//		s += H(i);
//	}
//	return s;
//}

int SUM(int n){
	int Hi;
	int H1 = 1, H2 = 2, H3 = 3, H4 = 4;
	s= H1 + H2 + H3 + H4;
	if(n <= 4) return n;
	for(int i=5; i<=n; i++){
	Hi = H1 + H2 - H3 + H4;
	s += Hi;
	H1 = H2;
	H2 = H3;
	H3 = H4;
	H4 = Hi;
	}
	return s;
}
int main(){
	
	cin>>n; 
	cout<< SUM(n);
	
	return 0;
}
