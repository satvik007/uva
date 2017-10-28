#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 100000000

int n, m, a[105][105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int u, v;
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) a[i][j] = inf;
            a[i][i] = 0;
        }
        for(int i=0; i<m; i++) {
            cin >> u >> v;
            a[u][v] = 1;
            a[v][u] = 1;
        }
        for(int k=0; k<n; k++) for(int i=0; i<n; i++) for(int j=0; j<n; j++)
                    a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
        int max1 = -1;
        int current;
        cin >> u >> v;
        for(int i=0; i<n; i++){
            current = a[u][i] + a[i][v];
            max1 = max(max1, current);
        }
        cout << "Case " << cas << ": " << max1 << "\n";
    }
    return 0;
}
