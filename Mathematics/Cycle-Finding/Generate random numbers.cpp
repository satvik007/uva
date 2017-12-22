#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef pair <int, int> ii;

long n;

ll f(ll x){
    string a = to_string(x * x);
    string zeroes(8 - a.size(), '0');
    a = zeroes + a;
    x = stoi(a.substr(2, 4));
    return x;
}

ii floydCycleFinding(int x0) {
    ll tortoise = f(x0), hare = f(f(x0));
    while (tortoise != hare) {
        tortoise = f(tortoise); hare = f(f(hare));
    }
    ll mu = 0; hare = x0;
    while (tortoise != hare) {
        tortoise = f(tortoise); hare = f(hare); mu++;
    }
    ll lambda = 1; hare = f(tortoise);
    while (tortoise != hare) {
        hare = f(hare); lambda++;
    }
    return ii(mu, lambda);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        ii ans = floydCycleFinding(n);
        cout << ans.second + ans.first<< "\n";
    }
    return 0;
}