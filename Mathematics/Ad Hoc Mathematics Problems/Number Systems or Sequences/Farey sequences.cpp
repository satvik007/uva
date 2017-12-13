#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> m){
        int a, b, pa, pb, ta, tb, tk;
        pa = 0, pb = 1, a = 1, b = n;
        while(--m) {
            tk = (n+pb)/b;
            ta = tk*a - pa;
            tb = tk*b - pb;
            pa = a, pb = b;
            a = ta, b = tb;
        }
        cout << a << "/" << b << "\n";
    }

    return 0;
}
