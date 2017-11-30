#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 1e9

int n, mf, f, s, t, res[205][205];
vector <vi> a;
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
        f = 0;
        bitset<205> visited; visited.set(s);
        queue <int> q; q.push(s);
        p.assign(205, -1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(auto v:a[u]){
                if(res[u][v] > 0 && !visited.test(v)){
                    visited.set(v);
                    q.push(v);
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
    int m, u, v, w, cas = 1;
    while(cin >> n, n){
        a.clear(); a.resize(n); memset(res, 0, sizeof res);
        cin >> s >> t >> m; s--; t--;
        for(int i=0; i<m; i++){
            cin >> u >> v >> w; u--; v--;
            res[u][v] += w;
            res[v][u] += w;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        EdmondKarp();
        cout << "Network " << (cas++) << "\nThe bandwidth is " << mf << ".\n\n";
    }
    return 0;
}