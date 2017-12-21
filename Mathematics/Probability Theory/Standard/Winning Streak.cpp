#include <bits/stdc++.h>
using namespace std;

int n;
double p, dp[502][502];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << fixed << setprecision(6);
    while(cin >> n >> p, n) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<=n; j++){
                if(abs(dp[i][j]) < 1e-10) continue;
                dp[i+1][j] += dp[i][j] * (1-p);
                for(int k=1; k<n-i; k++){
                    if(k <= j){
                        dp[i+1+k][j] += dp[i][j] * pow(p, k) * (1-p);
                    }else{
                        dp[i+1+k][k] += dp[i][j] * pow(p, k) * (1-p);
                    }
                }
                if(n-i <= j) dp[n][j] += dp[i][j] * pow(p, n - i);
                else dp[n][n-i] += dp[i][j] * pow(p, n-i);
            }
        }
        double ans = 0;
        for(int i=1; i<=n; i++){
            ans += i * dp[n][i];
        }
        cout << ans << "\n";
    }
    return 0;
}