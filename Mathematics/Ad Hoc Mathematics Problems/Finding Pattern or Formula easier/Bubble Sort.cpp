#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll n, tc;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    int cas = 1;
    cout << fixed;
    while(tc--){
        cin >> n;
        long double a = n * (n-1) / 4.0;
        cout << "Case " << cas++ << ": ";
        if(a == (ll)a) cout << (ll)a << "\n";
        else cout << ((ll)(2*a)) << "/" << 2 << "\n";
    }
    return 0;
}