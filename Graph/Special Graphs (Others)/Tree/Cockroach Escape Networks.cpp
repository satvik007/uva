#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

int tc, n, m, a[400][400];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    int N, u, v;
    for(int cas = 1; cas <= tc; cas++){
        cin >> n >> m;
        N = n+m;
        int size = n;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++) a[i][j] = inf;
            a[i][i] = 0;
        }
        while(m--){
            cin >> u >> v;
            a[u][size] = a[size][u] = 1;
            a[v][size] = a[size][v] = 1;
            size++;
        }
        for(int k=0; k<N; k++)
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
        int ans = inf;
        for(int i=0; i<N; i++){
            ans = min(ans, *max_element(a[i], a[i]+n));
        }
        cout << "Case #" << cas << ":\n" << ans << "\n\n";
    }
    return 0;
}