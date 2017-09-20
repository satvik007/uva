#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int n, lo, hi, u, v, d;

vector <ll> b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    vector <string> a;
    vi mask, b;
    for(int cas = 1; cas <= t; cas++){
        cout << "Case " << cas << ": ";
        cin >> n >> d;
        a.resize(n);
        b.resize(n+2);
        mask.resize(n+2);
        mask[0] = 0; mask[n+1] = 0;
        b[0] = 0; b[n+1] = d;
        for(int i=0; i<n; i++){
            cin >> a[i];
            b[i+1] = stoi(a[i].substr(2));
            mask[i+1] = (a[i][0] == 'B' ? 0 : 1);
        }
        for (int i = 1; i <= n; i++) {
            if (mask[i] == 0) continue;
            if (mask[i-1] == 1) mask[i] = -1;
        }
        int p = 0;
        int m = 0;
        for (int i = 1; i < n+2; i++) {
            if (mask[i] == -1) continue;
            m = max(m, b[i] - p);
            p = b[i];
        }
        p = 0;
        for (int i = 1; i < n+2; i++) {
            if (mask[i] == 1) continue;
            m = max(m, b[i] - p);
            p = b[i];
        }
        cout << m << "\n";
    }
}
