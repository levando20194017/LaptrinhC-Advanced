#include<iostream>
using namespace std;
int a[8]={2, 3, 7, 1, 2, 3, 4, 5};
int s[8];
int trace[8];
int DS(int *a){
	s[0]= a[0];
	int max=a[0];
	for(int i=1; i<8; i++){
		
		s[i]=a[i];
		
		for(int j=i-1; j>=0; j--){
			if(a[i]>a[j]){
				if(s[j]+a[i]>s[i]){
					
				s[i]= s[j]+ a[i];
			}		
		}
	}
	max= max > s[i] ? max:s[i];
	}
	return max;
}
int main(){
	cout<< DS(a);
	return 0;
}
