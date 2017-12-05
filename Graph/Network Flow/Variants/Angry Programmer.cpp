#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

int n, m, f, mf, s, t, res[105][105];
vi p;

void augment(int v, int minEdge){
    if(v == s) f = minEdge;
    else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}
void EdmondKarp(){
    mf = 0;
    while(true){
        f = 0; p.assign(105, -1);
        queue <int> q; q.push(s);
        bitset <105> visited; visited.set(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v=0; v<=2*n; v++){
                if(res[u][v] > 0 && !visited.test(v)){
                    visited.set(v); q.push(v);
                    p[v] = u;
                }
            }
        }
        augment(t, inf);
        if(!f) break;
        mf += f;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v, w;
    while(cin >> n >> m, n||m){
        memset(res, 0, sizeof res);
        s = 0; t = n-1;
        res[0][n] = inf;
        for(int i=0; i<n-2; i++){
            cin >> u >> v; u--;
            res[u][u+n] = v;
        }
        for(int i=0; i<m; i++){
            cin >> u >> v >> w; u--; v--;
            res[u+n][v] = w;
            res[v+n][u] = w;
        }
        res[n-1][n+n-1] = inf;
        EdmondKarp();
        cout << mf << "\n";
    }
    return 0;
}