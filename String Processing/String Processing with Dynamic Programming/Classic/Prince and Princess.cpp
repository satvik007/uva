#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

const int maxn = 250 + 5, inf = (int)1e9, val = maxn * maxn;
int d[val], princess[val], num[val], g[val];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc, n, p, q, temp; cin >> tc;
    for(int cas = 1; cas <= tc; cas++){
        cin >> n >> p >> q;
        memset(num, 0, sizeof num);
        for(int i=1; i<=p+1; i++){
            cin >> temp; num[temp] = i;
        }
        int m = 1;
        for(int i=1; i<=q+1; i++){
            cin >> temp;
            if(num[temp]) princess[m++] = num[temp];
        }
        for(int i=1; i<m; i++) g[i] = inf;
        int ret = -1;
        for(int i=1; i<m; i++){
            int k = lower_bound(g, g+m, princess[i]) - g;
            d[i] = k;
            g[k] = princess[i];
            ret = max(ret, d[i]);
        }
        cout << "Case " << cas << ": " << ret << "\n";
    }
    return 0;
}