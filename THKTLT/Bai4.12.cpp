#include<bits/stdc++.h>
using namespace std;

long long n;
vector<long long> vec;
vector<long long> L; 
vector<long long> R; 

void inputData(){
    cin >> n;
    vec.push_back(-1); 
    for(long long i=0; i<n; i++){
        long long ctt;
        cin >> ctt;
        vec.push_back(ctt);
    }
    vec.push_back(-1);
}

void sol(){
    while(true){
        inputData();
        if(n==0) return;

        stack<long long> st; 
        L.resize(n+2);
        R.resize(n+2);
        for(long long i=1; i<=n+1; i++){
            while(!st.empty() && vec[i] < vec[st.top()]){
                L[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for(long long i=n; i>=0; i--){
            while(!st.empty() && vec[i] < vec[st.top()]){
                R[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long maxh = 0;
        for(long long i=1; i<=n; i++){
            long long h = (L[i] - R[i] -1)*vec[i];
            if(h > maxh) maxh = h;
        }

        cout << maxh << endl; break;

        vec.erase(vec.begin(),vec.end());
        L.erase(L.begin(),L.end());
        R.erase(R.begin(),R.end());
    }
}

int main(){
	cout<<"Le Van Do 20194017";
    sol();
    return 0;
}
