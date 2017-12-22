#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, N;

ll next(ll x) {
    return (a * x % N * x % N + b) % N;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (cin >> N >> a >> b) {
        ll slow = next(0), fast = next(next(0));
        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        int lambda = 1;
        slow = next(slow);
        while (slow != fast) {
            slow = next(slow);
            lambda++;
        }
        cout << ((int)N - lambda) << "\n";
    }
    return 0;
}