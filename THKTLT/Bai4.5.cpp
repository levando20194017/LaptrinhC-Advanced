#include<iostream>
#include<vector>
#include<list>
#include<stack>

using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size(), false);
    S.push(1);

    while (!S.empty())
    {
        int u = S.top();
        if (!visited[u])
        {
            visited[u] = true;
            cout << u << endl;
        }

        if (!adj[u].empty())
        {
            int v = adj[u].front();
            adj[u].pop_front();
            if (!visited.at(v))
                S.push(v);
        }
        else
            S.pop();
    }
}

int main()
{
    cout << "Le Van Do 20194017" << endl;
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
}
