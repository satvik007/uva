#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll n, k, mod, tc;
vi a;

ll modExp(ll x, ll e){
    ll r = 1;

    for (; e; e /= 2){
        if (e % 2)
            r = (r * x) % mod;
        x = (x * x) % mod;
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    int cas = 1;
    while(tc--){
        cin >> n >> k >> mod;
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        cout << "Case " << cas++ << ": ";
        ll total = 0;
        for (int i = 0; i < n; i++){
            total = (total + a[i] % mod) % mod;
        }
        cout << ((k % mod) * (total % mod) * (modExp(n,k-1) % mod)) % mod << "\n";
    }
    return 0;
}