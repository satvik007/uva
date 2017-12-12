#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef long double ld;
typedef pair <ld, ld> ii;

ld dist;
int n, m;

ii func(int n){
    ll a = (ll)sqrt(n);
    ld x, y;
    ll next = (a+1)*(a+1) - 1;
    ll mid = (next + a*a) >> 1;
    ll diff = (n - mid);
    if(abs(diff) % 2 && a % 2 || !(a % 2) && !(abs(diff) % 2)){
        x = (a * 3 + 2) * dist;
        y = 0.5 * diff;
    }
    else{
        y = 0.5 * diff;
        x = (a * 3 + 1) * dist;
    }
    return {x, y};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    dist = 0.5L / sqrt(3.0L);

    cout << setprecision(3) << fixed;
    while(cin >> n >> m){
        ii x = func(n);
        ii y = func(m);
        cout << hypot(x.first - y.first, x.second - y.second) << "\n";
    }
    return 0;
}