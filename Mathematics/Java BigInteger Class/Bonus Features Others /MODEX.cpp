#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

template <typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll x, y, z;
    int tc;
    cin >> tc;
    while(tc--){
        cin >> x >> y >> z;
        cout << modpow(x, y, z) << "\n";
    }

    return 0;
}