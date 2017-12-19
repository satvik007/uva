#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef unsigned long long ull;

int ipow(int base, int exp, int modulo){
    int result = 1; base %= modulo;
    while (exp){
        if (exp & 1)
            result = (result * base) % modulo;
        exp >>= 1;
        base = (base * base) % modulo;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m;
    int mod = (int)1e9;
    while(cin >> n >> m){
        ll res = 1;
        for(int i=0; i<m; i++){
            res = res * ( n - i);
            while(res % 10 == 0) res /= 10;
            res = res % mod;
        }
        cout << res % 10 << "\n";
    }
    return 0;
}