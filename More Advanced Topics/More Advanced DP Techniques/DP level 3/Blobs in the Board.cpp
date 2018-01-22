#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9

int n, m, k, val;
int dp[4][4][(1<<16)+5];

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int solve(int mask){
    if(__builtin_popcount(mask) == 1) return 1;
    if(dp[n-1][m-1][mask] != -1) return dp[n-1][m-1][mask];
    int ans = 0, temp, tx, ty, nx, ny;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            if (mask & (1 << (i * m + j))) {
                for (int k = 0; k < 8; k++) {
                    tx = i + dr[k];
                    ty = j + dc[k];
                    nx = tx + dr[k];
                    ny = ty + dc[k];
                    if (tx >= 0 && ty >= 0 && tx < n && ty < m && (mask & (1 << (m * tx + ty)))
                        && nx >= 0 && ny >= 0 && nx < n && ny < m && !(mask & (1 << (m * nx + ny)))) {
                        temp = mask ^ (1 << (m * tx + ty)) ^ (1 << (i * m + j));
                        temp |= (1 << (m * nx + ny));
                        ans += solve(temp);
                    }
                }
            }
        }
    }
    return dp[n-1][m-1][mask] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    int cas = 1;
    memset(dp, -1, sizeof dp);
    while(tc--){
        cin >> n >> m >> k;
        int u, v;
        int mask = 0;
        for(int i=0; i<k; i++){
            cin >> u >> v; u--; v--;
            mask |= (1<<(u * m + v));
        }
        int ans = solve(mask);
        cout << "Case " << cas++ << ": " << ans << "\n";
    }
    return 0;
}