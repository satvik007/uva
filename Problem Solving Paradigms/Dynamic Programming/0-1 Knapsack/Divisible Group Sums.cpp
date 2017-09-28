#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, q, d, m;
int a[205];
int dp[205][15][25];

int solve(){
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=m; j++){
            for(int k=0; k<d; k++){
                dp[i][j][k] += dp[i-1][j][k];
                if(j){
                    int x = (d+k - a[i-1]%d)%d;
                    dp[i][j][k] += dp[i-1][j-1][x];
                }
            }
        }
    }
    return dp[n][m][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> q, n||q){
        cout << "SET " << (cas++) << ":\n";
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<q; i++){
            cin >> d >> m;
            cout << "QUERY " << (i+1) << ": " << solve() << "\n";
        }
    }
    return 0;
}
