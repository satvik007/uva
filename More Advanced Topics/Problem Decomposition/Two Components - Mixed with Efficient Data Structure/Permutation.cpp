#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

#define LSOne(S) (S & (-S))

class FenwickTree {
private:
    vi ft;

public:
    FenwickTree() {}
    // initialization: n + 1 zeroes, ignore index 0
    FenwickTree(int n) { ft.assign(n + 1, 0); }

    int rsq(int b) {                                     // returns RSQ(1, b)
        int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
        return sum; }

    int rsq(int a, int b) {                              // returns RSQ(a, b)
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

    // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
    void adjust(int k, int v) {                    // note: n = ft.size() - 1
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};


int n, a[60000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];
        FenwickTree ft(n);
        for(int i=1; i<=n; i++){
            ft.adjust(i, 1);
        }
        int lo, mid, hi, ans;
        for(int i=0; i<n; i++){
            lo = 1; hi = n; ans = n;
            while(lo <= hi){
                mid = lo + (hi-lo)/2;
                if(ft.rsq(mid) > a[i]) ans = min(ans, mid), hi = mid - 1;
                else lo = mid + 1;
            }
            if(i) cout << " " << ans;
            else cout << ans;
            ft.adjust(ans, -1);
        }
        cout << "\n";
    }
    return 0;
}
