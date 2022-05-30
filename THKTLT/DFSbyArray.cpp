#include <bits/stdc++.h>
using namespace std;
 
int a[101][101]; 
 
int n, m, Free[101], u, v, s;
 
void DFS(int u)
{
    cout << u << endl;
    Free[u] = false;
    for (int v = 1; v <= n; v++)
        if (a[u][v] == 1 && Free[v])
            DFS(v);
}
 
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = 0;
 
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
 
    for (int i = 1; i <= n; i++)
        Free[i] = 1;
    DFS(s);
    return 0;
}
