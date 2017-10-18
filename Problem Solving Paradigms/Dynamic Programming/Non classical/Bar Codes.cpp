#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int N, M, K;
ll dp[55][55];

ll solve(int n, int k){
    if(n == 0 && k == 0) return 1;
    if(n == 0 || k == 0) return 0;
    if(dp[n][k] != -1) return dp[n][k];
    ll ans = 0;
    for(int i=1; i<=M; i++){
        if(n-i<0) break;
        ans += solve(n-i, k-1);
    }
    return dp[n][k] = ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> N >> K >> M){
        memset(dp, -1, sizeof dp);
        cout << solve(N, K) << "\n";
    }
}
