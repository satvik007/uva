#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int dp[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    dp[0] = 1; dp[1] = 2; dp[2] = 2;
    for (int i = 3; i < 76; i++)
        dp[i] = dp[i - 2] + dp[i - 3];
    int n;
    while(cin >> n) cout << dp[n-1] << "\n";
    return 0;
}