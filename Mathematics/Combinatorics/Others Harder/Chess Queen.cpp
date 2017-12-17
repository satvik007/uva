#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll m, n;
    ll dp[1000002];
    dp[1] = 0;
    for(int i=2; i<=1000000; i++){
        dp[i] = dp[i-1] + 2L * 2 * i * (i - 1);
    }
    while (cin >> m >> n, m) {
        ll result = 0;
        if (m < n)
            swap(m, n);
        result += m * n * (n - 1);
        result += n * m * (m - 1);
        result += dp[n-1];
        result += 2 * (m - n + 1) * n * (n - 1);
        cout << result << "\n";
    }
}