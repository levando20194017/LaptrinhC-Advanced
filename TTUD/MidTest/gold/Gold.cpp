#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+5;



int N , L1 ,L2;
int a[MAX];
int F[MAX];
int best;
deque<int> d;



void solve()
{
cin>>N>>L1>>L2;
best = 0;
for(int i = 1 ; i<=N ; ++i) cin>>a[i];



for(int i = 1; i<=N ; i++)
{
F[i] =a[i];
while(!d.empty()&&d.front()< i-L2) d.pop_front();
if(i - L1 >0)
{
while(!d.empty()&&F[d.back()]<F[i-L1]) d.pop_back();
d.push_back(i-L1);
}
F[i] = F[i] + (d.empty()?0:F[d.front()]);
best = max(best , F[i]);
}
cout<<best<<endl;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
solve();
}
