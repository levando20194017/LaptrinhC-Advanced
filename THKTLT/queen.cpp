#include<iostream>
using namespace std;
int s[8][8];
int count=0;
int k;
int Try(int n){
	for(int i=0; i<8; i++){
	if(s[n][i]==0){
		s[n][i]=1;
		s[n+1][i]=1;
		s[n+1][i+1]=1;
		s[n+1][i-1]=1;
		Try(n+1);
		if(n==7){
		for( k=0; k<8; k++){
			if(s[n][i]==0) count++;
		}
	 //return count;
	}
}
//s[n][i]=0;
//s[n+1][i]=0;
//s[n+1][i-1]=0;
//s[n+1][i+1]=0;
}
return count;
}
int main(){
	cout<<Try(0);
	return 0;
}

