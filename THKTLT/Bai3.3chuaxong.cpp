#include<iostream>
using namespace std;
int n;
int s=0;
int A[8][8];
int B[8][8];
int mazz=10000;
int count =0;
int MIN(int i, int count){
	for(int j= 1; j<=n; j++){
		if(i!=j){
		if(B[i][j]==0 && B[j][i]==0){
//		count++;
		 s= s+ A[i][j];
		 B[i][j]=1;
		 B[j][i]=1;
		 if(count==n-1){
		 	s=s+ A[j][1];
		 	if(s<mazz) mazz=s;
		 	//s=0;
		 }
		 else{
		 s= s+ MIN(j, count+1);
	}
		 B[i][j]=0;
		 B[j][i]=0;
	}
	}
}
return mazz;
}

int main(){
cout<<B[0][0];
	cin>>n;
	for(int i=1 ; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>A[i][j];
		}
	}
	cout<<MIN(1,1);
	return 0;
}
