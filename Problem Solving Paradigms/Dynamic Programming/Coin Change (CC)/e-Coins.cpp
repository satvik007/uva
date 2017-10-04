#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int w1[50], w2[50];
int dp[305][305];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int m, s;
        cin >> m >> s;
        for(int i=0; i<m; i++) cin >> w1[i] >> w2[i];
        for(int i=0; i<=s; i++) for(int j=0; j<=s; j++) dp[i][j] = INT_MAX;
        dp[0][0] = 0;
        for(int i=0; i<m; i++)
            for(int v1 = w1[i]; v1<=s; v1++)
                for(int v2 = w2[i]; v2 <= s; v2++){
                    if(dp[v1-w1[i]][v2-w2[i]] != INT_MAX){
                        dp[v1][v2] = min(dp[v1][v2], dp[v1-w1[i]][v2-w2[i]]+1);
                    }
                }
        int ans = INT_MAX;
        int max1 = s*s;
        for(int i=0; i<=s; i++){
            for(int j=0; j<=s; j++){
                if(i*i+j*j == max1 && dp[i][j] != INT_MAX){
                    if(ans > dp[i][j]) ans = dp[i][j];
                }
            }
        }
        if(ans != INT_MAX) cout << ans << "\n";
        else cout << "not possible\n";
    }
    return 0;
}