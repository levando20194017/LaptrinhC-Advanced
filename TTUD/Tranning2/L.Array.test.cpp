#include<iostream>
using namespace std;
int n;
bool trace(int k, int a[]){
	int m = 1;
	for(int i=1; i<n; i++){
			m = m * a[i];
			if(m<0){
				int n=1;
				for(int j=i+1; j<k; j++){
					n = n * a[j];
					if(n>0){
						int nhan = 1;
						for(int o = j; o<n; o++){
							nhan = nhan * a[o];
							if(nhan == 0) return true;
						}
					} 
				}
			}
		}
	}
int main(){
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int b[n], c[n], d[n];
	for(int i=0; i<n; i++){
		
	}
	return 0;
}
