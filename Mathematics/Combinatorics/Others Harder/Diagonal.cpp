#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n, n){
        cout << "Case " << cas++ << ": ";
        ll lo = 3, hi = INT_MAX, mid;
        while(lo < hi){
            mid = lo + (hi - lo)/2;
            if(mid * (mid - 3) /2 < n) lo = mid + 1;
            else hi = mid;
        }
        cout << hi << endl;
    }
    return 0;
}