#include <bits/stdc++.h>
using namespace std;

struct st{
    int i, j, s;
    st(int _i = 0, int _j = 0, int _s=0): i(_i), j(_j), s(_s){}
};

int main() {
	cout<<"Le Van Do 20194017\n";
    int n, M;
    cin >> n >> M;
    int m[n+1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];
    stack<st> s;
    //# sum of selected weights
    int sum = 0;
    s.push(st(1, -1, -m[1]));
    s.push(st(1, 0, 0));
    s.push(st(1, 1, m[1]));
    while (!s.empty()){
        st top = s.top();
        if (top.i >= n){
            if (top.s == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            continue;
        }

        //# Kh? d? quy
        s.pop();
        x[top.i]=top.j;
        s.push(st(top.i+1, -1, top.s-m[top.i+1]));
        s.push(st(top.i+1, 0,top.s));
        s.push(st(top.i+1, 1,top.s+m[top.i+1]));
    }
    cout << -1;

    return 0;
}
