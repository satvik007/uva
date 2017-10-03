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
/*
state:
    dp[i][j][k] - how many ways to select j numbers from i numbers, and with remainder k when the sum of those j numbers divides d

transition:
    dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][K], K equals the remainder before we select number j

this dp transition looks just like the one used to generate combination table:
    dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
which also can generate the famous pascal's triangle...
*/
