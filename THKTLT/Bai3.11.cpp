#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int n, r;
int pr[MAX][MAX];
int x[MAX];
bool visited[MAX];
vector<int> vt;
int min_pr;
int sum_pr;
int start, des, number;

void input(){
    cin >> n >> r;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> pr[i][j];
        }
}

bool check(int a, int i){
    if(visited[vt[i]]) return false;
    if(pr[x[a-1]][vt[i]] == 0) return false;
    return true;
}

void solution(){
    if(pr[x[number-2]][des] == 0) return;
    min_pr = min(min_pr, sum_pr + pr[x[number-2]][des]);
}

void TRY(int a){
    for(int i=1; i<number-1; i++){
        if(check(a, i)){
            visited[vt[i]] = true;
            sum_pr += pr[x[a-1]][vt[i]];

            x[a] = vt[i];
            if(a == number-2) solution();
            else TRY(a+1);

            visited[vt[i]] = false;
            sum_pr -= pr[x[a-1]][vt[i]];
        }
    }
}

int main(){
	cout<<"Le Van Do 20194017\n";
    string str;
    input(); getline(cin,str);

    while(r > 0){
        min_pr = INT_MAX;
        sum_pr = 0;

        getline(cin, str);
        while (!str.empty()){
            stringstream convert(str.substr(0, str.find(" ")));
            int tmp = 0;
            convert >> tmp;
            vt.push_back(tmp - 1);

            if (str.find(" ") > str.size()){
                break;
            } else {
                str.erase(0, str.find(" ") + 1); // Update string
            }
        }

        // Bat dau khoi tao cac du lieu can thiet truoc khi quay lui
        start = vt[0]; // diem bat dau dau
        des = vt[vt.size()-1]; // diem dich
        number = vt.size(); // so diem phai di qua
        x[0] = start; x[number-1] = des;
        for(int i=0; i<n; i++)
            visited[i] = false;

        TRY(1);

        // In ra ket qua
        if(min_pr == INT_MAX) cout << "0" << endl;
        else cout << min_pr << endl;

        // Xoa vector va chuyen sang khach tiep theo
        vt.erase(vt.begin(), vt.end());
        r--;
    }
}
