#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn 405
#define inf (int)1e9

int n, m, s, t, d;
vi a[maxn];
int dp[maxn][maxn];

int solve(int u, int left){
    if(left == 0){
        if(u == t) return 1;
        return 0;
    }
    if(dp[u][left] != -1) return dp[left][u];
    int ans = 0;
    for(auto v:a[u]){
        int current = solve(v, left-1);
        if(current > ans){
            return dp[u][left] = current;
        }
    }
    return dp[u][left] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> m, n||m){
        for(int i=0; i<n; i++) a[i].clear();
        int u, v;
        for(int i=0; i<m; i++){
            cin >> u >> v; u--; v--;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        cin >> s >> t >> d; s--; t--;
        memset(dp, -1, sizeof dp);
        int ans = solve(s, d);
        if(ans) cout << "Yes, Teobaldo can travel.\n";
        else cout << "No, Teobaldo can not travel.\n";
    }
    return 0;
}