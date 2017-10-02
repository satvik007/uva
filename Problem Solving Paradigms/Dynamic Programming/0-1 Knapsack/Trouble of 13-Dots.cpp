#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int m, n;
int p[105], f[105];
int dp[105][10005];

int solve(int id, int money){
    if(money > m+200) return -10000;
    if(id == n){
        if(money <= m) return 0;
        if(money <= 2000) return -1000;
        return 0;
    }
    if(dp[id][money] != -1) return dp[id][money];
    return dp[id][money] = max(solve(id+1, money), f[id] + solve(id+1, money + p[id]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> m >> n){
        for(int i=0; i<n; i++){
            cin >> p[i] >> f[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0) << "\n";
    }
}