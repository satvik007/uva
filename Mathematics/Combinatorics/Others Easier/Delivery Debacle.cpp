#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll dp[50];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, tc;
    dp[0] = dp[1] = 1; dp[2] = 5;
    for(int i=3; i<41; i++){
        dp[i] = dp[i-1] + 4*dp[i-2] + 2*dp[i-3];
    }
    cin >> tc;
    while(tc--){
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}