#include<bits/stdc++.h>
using namespace std;
struct data {
    int ai;
    int ki;

    data(int ai, int ki){
        this->ai = ai;
        this->ki = ki;
    }
};

struct SoSanh{
    bool operator() (data a, data b){
        int ra, rb;

        if(a.ai <= a.ki) ra = a.ai;
        else ra = a.ki;

        if(b.ai <= b.ki) rb = b.ai;
        else rb = b.ki;

        return ra < rb;
    }
};

int n, s, kill_enemy, TongEnemy;
priority_queue<data, vector<data>, SoSanh> p_q;

void input(){
    cin >> n >> s;
    kill_enemy = 0;
    TongEnemy = 0;
    for(int i=0; i<n; i++){
        int ctt1, ctt2;
        cin >> ctt1 >> ctt2;
        TongEnemy += ctt1;
        p_q.push(data(ctt1, ctt2));
    }
}

void sol(){
    while(!p_q.empty() && s>0){
        data inf = p_q.top(); p_q.pop();

        if(inf.ai <= inf.ki){
            kill_enemy += inf.ai;
        } else {
            int nenemy = inf.ai - inf.ki;
            p_q.push(data(nenemy, inf.ki));
            kill_enemy += inf.ki;
        }

        s -= 1;
    }
}

int calc_enemy(){

    return TongEnemy - kill_enemy;
}

int main(){
	cout<<"Le Van Do 20194017";
    input();
    sol();
    cout << calc_enemy();

    return 0;
}
