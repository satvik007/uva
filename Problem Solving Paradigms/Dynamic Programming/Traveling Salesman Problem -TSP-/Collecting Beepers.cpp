#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int xsize, ysize, n, x[11], y[11], dist[11][11], memo[11][1<<11];

int tsp(int pos, int bitmask){
    if(bitmask == (1 << (n+1))-1) return dist[pos][0];
    if(memo[pos][bitmask] != -1) return memo[pos][bitmask];
    int ans = 2000000000;
    for(int nxt = 0; nxt <= n; nxt++){
        if(nxt != pos && !(bitmask & (1 << nxt)))
            ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1<<nxt)));
    }
    return memo[pos][bitmask] = ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> xsize >> ysize;
        cin >> x[0] >> y[0];
        cin >> n;
        for(int i=1; i<=n; i++) cin >> x[i] >> y[i];
        memset(memo, -1, sizeof(memo));
        for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
        cout << "The shortest path has length " << tsp(0, 1) << "\n";
    }
}