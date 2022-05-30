#include<iostream>
using namespace std;
int Max;
int a[1000][1000], b[1000][1000];
int Try(int k, int (*a)[1000], int (*b)[1000], int L, int C){
	int count1=0;
	int count2=0;
	int count3=0;
	int count4=0;
	int count5=0;
	int count6=0;
	for(int i=0; i<L; i++){
		for(int j=0; j<C; j++){
			if(a[i][j] == 1){
				if(a[i][j] == b[i-k][j+k]) count1 ++;
				if(a[i][j] == b[i+k][j-k]) count2 ++;
				if(a[i][j] == b[i-k][j]) count3++;
				if(a[i][j] == b[i+k][j]) count4++;
				if(a[i][j] == b[i][j-k]) count5++;
				if(a[i][j] == b[i][j+k]) count6++;
			}
		}
	}
	if(count1 > Max) Max = count1;
	if(count2 > Max) Max = count2;
	if(count3 > Max) Max = count3;
	if(count4 > Max) Max = count4;
	if(count5 > Max) Max = count5;
	if(count6 > Max) Max = count6;
	if(k==C) return Max;
	else Try(k+1,a,b,L,C);
}
int main(){
	int T;
	cin>>T;
	while(T--){
	int L,C;
	cin>>L>>C;
	for(int i=0; i<L; i++){
		for(int j=0; j<C; j++){
			cin>>a[i][j];
		}
	}
	for(int i=0; i<L; i++){
		for(int j=0; j<C; j++){
			cin>>b[i][j];
		}
	}
	cout<< Try(0, a, b, L, C);
	Max = 0;
	}
	return 0;
}
