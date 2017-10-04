#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 1000000000
int n, m;
int coins[105];

int dp[20001];

void solve(){
    dp[0] = 0;
    for (int i=1; i<=20005; i++)
        dp[i] = inf;
    for (int i=0; i<n; i++){
        for (int v = 20001 - coins[i] - 1; v >= 0; v--){
            if (dp[v] < inf)
                dp[v+coins[i]] = min(dp[v+coins[i]], dp[v]+1);
        }
    }
    for(int i=m; i<=20001; i++) {
        if(dp[i] != inf){
            cout << i << " " << dp[i] << "\n";
            break;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        for(int i=0; i<n; i++) cin >> coins[i];
        //sort(coins, coins+n);
        solve();
    }
}
