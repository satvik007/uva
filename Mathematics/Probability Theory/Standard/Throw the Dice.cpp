#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

cpp_int dp[55][4004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, x;
    while (cin >> k >> n >> x) {
        cpp_int nom = 0;
        if (x <= k * n && x >= n) {
            for (int i = 0; i <= 50; i++)
                for (int j = 0; j <= 4000; j++)
                    dp[i][j] = 0;

            dp[0][0] = 1;

            for (int i = 1; i <= k; i++)
                dp[1][i] = 1;

            for (int i = 2; i <= n; i++) {
                cpp_int ps = 0;
                for (int j = i; j <= k * i; j++) {
                    ps += dp[i - 1][j - 1];
                    if (j - i >= k)ps -= dp[i - 1][j - k - 1];
                    dp[i][j] = ps;
                }
            }
            nom = dp[n][x];
        }

        cpp_int denom = 1;
        for (int i = 1; i <= n; i++)denom *= k;

        cout << nom << "/" << denom << endl;
    }

    return 0;
}
