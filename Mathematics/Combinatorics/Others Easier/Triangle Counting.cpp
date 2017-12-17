#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull dp[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    dp[3] = 0, dp[4] = 1;
    ull i, b;
    for(i = 5; i <= 1000000; i++) {
        b = i/2 + 1;
        dp[i] = dp[i-1] + i*(i-1)-(i+1)*(i-b) - b*(b-1);
    }
    int n;
    while(cin >> n, n>=3) cout << dp[n] << "\n";
    return 0;
}