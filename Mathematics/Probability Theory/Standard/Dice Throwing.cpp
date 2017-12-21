#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef vector <int> vi;
#define inf (int)1e9

ll dp[25+5][25*6+5];
int n, k;

ll solve(int score, int dice){
    if(dice < 0) return 0;
    if(score >= k && dice == 0) return 1;
    if(dp[dice][score] != -1) return dp[dice][score];
    ll ans = 0;
    for(int i=1; i<=6; i++){
        ans += solve(score + i, dice - 1);
    }
    return dp[dice][score] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> k, n||k){
        memset(dp, -1, sizeof dp);
        ll ans = solve(0, n);
        ll res = 1;
        for(int i=0; i<n; i++){
            if(ans % 6 == 0) ans /= 6;
            else res *= 6;
        }
        ll gcd = __gcd(res, ans);
        res /= gcd; ans /= gcd;
        if(ans == 0 || ans == res) cout << ans << "\n";
        else cout << ans << "/" << res << "\n";
    }
    return 0;
}