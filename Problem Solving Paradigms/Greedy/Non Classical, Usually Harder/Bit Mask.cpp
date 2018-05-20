#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

ll n, u, v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 //   freopen("in.txt", "r", stdin);
 //   freopen("out.txt", "w", stdout);

    while(cin >> n >> u >> v) {
        ll ans = 0;
        for(int i = 31; i >= 0; i--) {
            if(n & (1LL << i)) {
                ll r = ans + (1LL << i);
                if(r <= u) ans += (1LL << i);
            } else {
                ll r = ans + (1LL << i);
                if(r <= v) ans += (1LL << i);
            }
        }

        cout << ans << "\n";
    }

}
