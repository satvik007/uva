#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

int n, tc;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    while(tc--){
        ll n, ans = 0; cin >> n;
        int k = sqrt(n);
        for (int i = 1; i <= k; ++i)
            ans += n / i + n / i;
        ans -= k * k;
        cout << ans << endl;
    }
    return 0;
}
