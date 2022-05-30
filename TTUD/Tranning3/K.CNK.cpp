#include<iostream>
using namespace std;
const unsigned long long N = 1e18;
const unsigned long long M = 1e18;
const int K = 1e5;
unsigned long long **c;

void allocate_mem(unsigned long long ***mt, unsigned long long m, unsigned long long n){
            unsigned long long **arr=(unsigned long long**)malloc(m*sizeof(unsigned long long*));
            for(unsigned long long i=0; i<m;i++){
            	*(arr+i)=(unsigned long long*)malloc(n*sizeof(unsigned long long));
			}
			*mt=arr;
}

unsigned long long Try(int k, unsigned long long n){
	if(k==0 || k==n) return c[k][n] = 1;
	if(c[k][n] == 0){
		c[k][n] = Try(k-1, n-1) + Try(k, n-1);
	}
	return c[k][n];
}

void free_mem(unsigned long long **mt, unsigned long long m, unsigned long long n){
	for(unsigned long long i=0;i<m;i++) delete[] mt[i];
	delete[] mt;
}
int main(){
	int T; cin>>T;
	for(int i=1; i<=T; i++){
	allocate_mem(&c, N, N);
	unsigned long long n,m;
	int k;
	cin>>n>>k>>m;
	cout<<Try(k,n)%m<<endl;
	free_mem(c, N, N);
	}
	return 0;
}
