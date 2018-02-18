#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn 140

int n, m;
vi edgeList[maxn];
int visited[maxn], match[maxn];
int check[maxn][maxn];
int in[maxn], out[maxn];
int a[maxn], b[maxn], h, w;
int c[maxn], d[maxn];

int augment(int u){
    if(visited[u]) return 0;
    visited[u] = 1;
    for(int v=0; v<w; v++){
        if(check[u][v] && (match[v] == -1 || augment(match[v]))){
            match[v] = u; return 1;
        }
    }
    return 0;
}

void solve(){
    memset(check, 0, sizeof check);
    int mcbm = 0;
    h = w = 0;
    memset(c, -1, sizeof c);
    memset(d, -1, sizeof d);
    for(int i=0; i<n; i++){
        if(out[i]){
            a[h] = i;
            c[i] = h++;
        }
        if(in[i]){
            b[w] = i;
            d[i] = w++;
        }
    }
    for(int i=0; i<h; i++){
        int u = a[i];
        for(auto v:edgeList[u]){
            if(d[v] != -1){
                check[i][d[v]] = 1;
            }
        }
    }
    memset(match, -1, sizeof match);
    for(int i=0; i<h; i++){
        memset(visited, 0, sizeof visited);
        mcbm += augment(i);
    }
    cout << n - mcbm << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i=0; i<n; i++) edgeList[i].clear();
        int u, v;
        memset(out, 0, sizeof out);
        memset(in, 0, sizeof in);
        for(int i=0; i<m; i++){
            cin >> u >> v; u--; v--;
            edgeList[u].push_back(v);
            out[u]++;
            in[v]++;
        }
        solve();
    }
    return 0;
}