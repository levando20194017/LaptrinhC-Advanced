#include <stdio.h>

int X[11] = {0,1,2,4,5,7,8,9,2,5,6};
int Y[11] = {0,2,3,1,5,4,6,8,7,8,3};
int n = 11;
int m = 11;
int P[100][100];
char trace[100][100];



int main(){
for(int i = 0; i <= n; i++)
P[i][0] = 0;
for(int j = 0; j <= m; j++)
P[0][j] = 0;
for(int i = 1; i <= n; i++){
for(int j = 1; j <= m; j++){
if(X[i] == Y[j]){
P[i][j] = P[i-1][j-1] + 1;
trace[i][j] = 'C';
}else{
if(P[i-1][j] > P[i][j-1]){
P[i][j] = P[i-1][j]; trace[i][j] = 'L';
}else{
P[i][j] = P[i][j-1]; trace[i][j] = 'T';
}
}
}
}
int i = n; int j = m;
while(i >= 1 && j >= 1){
if(trace[i][j] == 'C'){
printf("%d ",X[i]); i = i-1; j = j-1;
}else{
if(trace[i][j] == 'L') i = i-1;
else j = j-1;
}
}



}
