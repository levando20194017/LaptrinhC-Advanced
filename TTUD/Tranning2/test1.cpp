#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <list>
using namespace std;
struct State{
int x;
int y;
char* msg;// action to generate current state
State* p;// pointer to the state generating current state
};
bool visited[10000][10000];
queue<State*> Q;
list<State*> L;
State* target;
int a,b,c;
void initVisited(){
for(int x = 0; x < 10000; x++)
for(int y = 0; y < 10000; y++) visited[x][y] = false;
}
bool reachTarget(State* S){
return S->x == c || S->y == c || S->x + S->y == c;
}
void markVisit(State* S){
visited[S->x][S->y] = true;
}
void freeMemory(){
list<State*>::iterator it;
for(it = L.begin(); it != L.end(); it++){
delete *it;
}
}
bool genMove1Out(State* S){
if(visited[0][S->y]) return false;
State* newS = new State;
newS->x = 0;
newS->y = S->y;
newS->msg = "Do het nuoc o coc 1 ra ngoai";
newS->p = S;
Q.push(newS); markVisit(newS);
L.push_back(newS);
if(reachTarget(newS)){
target = newS;
return true;
}
return false;
}
bool genMove2Out(State* S){
if(visited[S->x][0]) return false;
State* newS = new State;
newS->x = S->x;
newS->y = 0;
newS->msg = "Do het nuoc o coc 2 ra ngoai";
newS->p = S;
Q.push(newS); markVisit(newS);
L.push_back(newS);
if(reachTarget(newS)){
target = newS;
return true;
}
return false;
}
bool genMove1Full2(State* S){
if(S->x+S->y < b) return false;
if(visited[S->x + S->y - b][b]) return false;
State* newS = new State;
newS->x = S->x + S->y - b;
newS->y = b;
newS->msg = "Do nuoc tu coc 1 vao day coc 2";
newS->p = S;
Q.push(newS); markVisit(newS);
L.push_back(newS);
if(reachTarget(newS)){
target = newS;
return true;
}
return false;
}
bool genMove2Full1(State* S){
if(S->x+S->y < a) return false;
if(visited[a][S->x + S->y - a]) return false;
State* newS = new State;
newS->x = a;
newS->y = S->x + S->y - a;
newS->msg = "Do nuoc tu coc 2 vao day coc 1";
newS->p = S;
Q.push(newS); markVisit(newS);
L.push_back(newS);
if(reachTarget(newS)){
target = newS;
return true;
}
return false;
}
bool genMoveAll12(State* S){
if(S->x + S->y > b) return false;
if(visited[0][S->x + S->y]) return false;
State* newS = new State;
newS->x = 0;
newS->y = S->x + S->y;
newS->msg = "Do het nuoc tu coc 1 sang coc 2";
newS->p = S;
Q.push(newS); markVisit(newS);
L.push_back(newS);
if(reachTarget(newS)){
target = newS;
return true;
}
return false;
}
bool genMoveAll21(State* S){
if(S->x + S->y > a) return false;
if(visited[S->x + S->y][0]) return false;
State* newS = new State;
newS->x = S->x + S->y;
newS->y = 0;
newS->msg = "Do het nuoc tu coc 2 sang coc 1";
newS->p = S;
Q.push(newS); markVisit(newS);
L.push_back(newS);
if(reachTarget(newS)){
target = newS;
return true;
}
return false;
}
bool genMoveFill1(State* S){
if(visited[a][S->y]) return false;
State* newS = new State;
newS->x = a;
newS->y = S->y;
newS->msg = "Do day nuoc vao coc 1";
newS->p = S;
Q.push(newS); markVisit(newS);
L.push_back(newS);
if(reachTarget(newS)){
target = newS;
return true;
}
return false;
}
bool genMoveFill2(State* S){
if(visited[S->x][b]) return false;
State* newS = new State;
newS->x = S->x;
newS->y = b;
newS->msg = "Do day nuoc vao coc 2";
newS->p = S;
Q.push(newS); markVisit(newS);
L.push_back(newS);
if(reachTarget(newS)){
target = newS;
return true;
}
return false;
}
void print(State* target){
printf("-----------RESULT------------\n");
if(target == NULL) printf("Khong co loi giai!!!!!!!");
State* currentS = target;
stack<State*> actions;
while(currentS != NULL){
actions.push(currentS);
currentS = currentS->p;
}
while(actions.size() > 0){
currentS = actions.top();
actions.pop();
printf("%s, (%d,%d)\n",currentS->msg,currentS->x, 
currentS->y);
}
}
void solve(){
initVisited();
// sinh ra trang thai ban dau (0,0) va dua vao Q
State* S = new State;
S->x = 0; S->y = 0; S->p = NULL;
Q.push(S); markVisit(S);
while(!Q.empty()){
State* S = Q.front(); Q.pop();
if(genMove1Out(S)) break; // (0,y)
if(genMove2Out(S)) break; // (x,0)
if(genMove1Full2(S)) break; // (x+y-b,b) if(x+y >= b)
if(genMoveAll12(S)) break; // (0,x+y) if(x+y <= b)
if(genMove2Full1(S)) break; // (a,x+y-a) if (x+y >= a)
if(genMoveAll21(S)) break;// (x+y,0) if(x+y <= a)
if(genMoveFill1(S)) break;// (a,y)
if(genMoveFill2(S)) break;// (x,b)
}
}
int main(){
a = 6;
b = 7;
c = 3;
target = NULL;
solve();
print(target);
freeMemory();
}

