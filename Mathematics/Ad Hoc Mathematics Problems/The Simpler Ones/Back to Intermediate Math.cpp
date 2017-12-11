#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc;
double d, v, u;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    cout << fixed << setprecision(3);
    for(int cas = 1; cas <= tc; cas++){
        cin >> d >> v >> u;
        cout << "Case " << cas << ": ";
        if(v >= u || v == 0) cout << "can't determine\n";
        else cout << (d/sqrt(u*u - v*v) - d/u) << "\n";
    }
    return 0;
}