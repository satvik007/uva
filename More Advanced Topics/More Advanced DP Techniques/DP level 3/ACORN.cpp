#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9

int n, h, f;
int dp[2010];
int acorn[2010][2010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    int m, u, v;
    while(tc--){
        cin >> n >> h >> f;
        memset(acorn, 0, sizeof acorn);
        for(int i=0; i<n; i++){
            cin >> m;
            for(int j=0; j<m; j++){
                cin >> u;
                acorn[i][u]++;
            }
        }
        memset(dp, 0, sizeof dp);
        for (int tree = 0; tree < n; tree++)
            dp[h] = max(dp[h], acorn[tree][h]);
        for (int height = h - 1; height >= 0; height--)
            for (int tree = 0; tree < n; tree++) {
                acorn[tree][height] += max(acorn[tree][height + 1],
                  ((height + f <= h) ? dp[height + f] : 0)); // from tree at height + f
                dp[height] = max(dp[height], acorn[tree][height]);
            }
        cout <<  dp[0] << "\n";
    }
    return 0;
}