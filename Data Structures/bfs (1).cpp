#include <bits/stdc++.h>
using namespace std;
#define N 100000
queue<int> Q;
vector<int> A[N];
int n,m;
int d[N];// d[v] khoang cach tu dinh xuat phat den dinh v trong BFS
int p[N];// p[v] dinh truoc (cha) cua dinh v
void input(){
    cin >> n >> m;
    for(int k = 1; k <= m; k++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
bool bfs(int u){
    d[u] = 0;
    p[u] = -1;
    Q.push(u);
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        for(int i = 0; i < A[v].size(); i++){
            int x = A[v][i];
            if(d[x] == -1){// chua duoc tham
                d[x] = d[v] + 1;
                p[x] = v;
                Q.push(x);
            }else{
                if(d[v] % 2 == d[x] % 2) return false;
            }
        }
    }
    return true;
}
void init(){
    for(int v = 1; v <= n; v++) d[v] = -1;// dinh v chua duoc tham

}
int main(){
    input();
    init();
    bool ok = bfs(1);
    //for(int v = 1; v <= n; v++) cout << "d[" << v << "] = " << d[v] << endl;
    if(!ok) cout << " NO" << endl; else cout << "YES" << endl;
}
