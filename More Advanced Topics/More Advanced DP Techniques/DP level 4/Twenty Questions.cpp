#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f

const int maxm = 11;
const int maxn = 128;

int n, m;
int a[maxn];
int dp[1<<maxm][1<<maxm];

int dfs(int S, int res) {
    if(dp[S][res] != -1) return dp[S][res];
    int cnt = 0;
    for(int i=0; i<n; i++)
        if((S & a[i]) == res) cnt++;
    if(cnt <= 1) return dp[S][res] = 0;
    dp[S][res] = INF;
    for(int i=0; i<m; i++) {
        if(S & (1 << i)) continue;
        int tmp = max(dfs(S | (1 << i), res), dfs(S | (1 << i), res | (1 << i))) + 1;
        dp[S][res] = min(dp[S][res], tmp);
    }
    return dp[S][res];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> m >> n, m || n) {
        char buf[maxm+2];
        int val;
        for(int i=0; i<n; i++) {
            cin >> buf;
            val = 0;
            for(int j=0; j<m; j++)
                if(buf[j] == '1')
                   val |= (1 << j);
            a[i] = val;
        }
        memset(dp, -1, sizeof dp);
        cout << dfs(0, 0) << "\n";
    }
    return 0;
}