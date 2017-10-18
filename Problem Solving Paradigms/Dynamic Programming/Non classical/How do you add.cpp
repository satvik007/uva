#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m;
    int dp[205][205] = {0};
    dp[0][0] = 1;
    for(int i=1; i<=200; i++){
        dp[i][0] = 1;
        for(int j=1; j<=i; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%1000000;
        }
    }
    while(cin >> n >> m, n||m){
        cout << dp[n+m-1][m-1] << "\n";
    }
}
