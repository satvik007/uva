#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 10000000
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, n;
    cin >> t;
    int dp[105][12];
    int wind[105][12];
    while(t--){
        cin >> n;
        n/=100;
        memset(wind, 0, sizeof wind);
        for(int i=9; i>=0; i--) for(int j=0; j<n; j++) cin >> wind[j][i];
        for(int i=0; i<102; i++){
            for(int j=0; j<10; j++) dp[i][j] = inf;
        }
        dp[0][0] = -wind[0][0];
        for(int i=1; i<=n; i++){
            for(int j=0; j<10; j++){
                dp[i][j] = min(dp[i][j], dp[i-1][j]+30);
                if(j>0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]+60);
                if(j<9) dp[i][j] = min(dp[i][j], dp[i-1][j+1]+20);
                dp[i][j] += -wind[i][j];
                //cout << dp[i][j] << endl;
            }
        }
        cout << dp[n][0] << "\n\n";
    }
}
