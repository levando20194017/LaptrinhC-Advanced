#include <bits/stdc++.h>
using namespace std;
#define N 100
vector<int> A[N];// A[v] la DS cac dinh ke voi v
int n,m;
int p[N];
int d[N];
int f[N];
char color[N];
int t;
int nbCC;
int icc[N];// icc[v] is the index of connected component containing v
void input(){
    cin >> n >> m;
    for(int k = 1; k <= m; k++){
        int u,v;
        cin >> u >> v;
        A[v].push_back(u);// them u vao DS ke cua v
        A[u].push_back(v);// them v vao DS ke cua u
    }
}
void print(){
    for(int v = 1; v <= n; v++){
        cout << "A[" << v << "]: ";
        for(int i = 0; i < A[v].size(); i++){
            int u = A[v][i];
            cout << u << " ";
        }
        cout << endl;
    }
}
void dfs(int u){
    t++;
    d[u] = t;
    color[u] = 'G';
    icc[u] = nbCC;
    for(int i = 0; i < A[u].size(); i++){
        int  v = A[u][i];
        if(color[v] == 'W'){
            p[v] = u;
            dfs(v);
        }else{
            //return true;// co chu trinh
        }
    }
    t++;
    f[u] = t;
    color[u] = 'B';// dinh u da duyet xong
}
void dfs(){
    for(int  v = 1; v <= n; v++){
        color[v] = 'W';
    }
    nbCC = 0;
    for(int v = 1; v <= n; v++)if(color[v] == 'W'){
        nbCC += 1;
        dfs(v);
    }

    for(int c = 1;  c<= nbCC; c++){
        cout << "connected component " << c << ": ";
        for(int v = 1; v <= n; v++) if(icc[v] == c) cout << v << " ";
        cout << endl;
    }
}
int main(){
    input();
    print();
    dfs();
}
