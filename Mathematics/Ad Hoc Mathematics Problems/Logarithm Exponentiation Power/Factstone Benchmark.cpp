#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll fac(ll k){
    ll res = 1;
    for(int i=1; i<=k; i++) res *= i;
    return res;
}

ll ipow(ll base, ll exp) {
    ll result = 1;
    while (exp) {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

int b[] = {3, 5, 8, 12, 20, 34, 57, 98, 170, 300, 536, 966, 1754, 3210, 5910, 10944, 20366, 38064, 71421, 134480, 254016 };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n, n){
        n -= 1960; n /= 10;
        cout << b[n] << "\n";
    }
    return 0;
}
