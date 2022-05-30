#include<iostream>
using namespace std;
int n=4;
int k=4;
int a[1000];
void print(){
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}
int s = 0;
int lietke(int m, int k){
	for(int j=0; j<2; j++){
		for(int i=1; i<k; i++){
			s += a[m-i];
		}
		if(s +j < k){
			a[m] = j;
			if(m==n-1) print();
			else
			lietke(m+1, k);
		}
		s=0;
		}
		}
int main(){
	lietke(0, k);
	return 0;
}
