#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
vector <vi> a;
int dist[305][305], colors[305], visited[305];

void dfs(int u, int color){
    visited[u] = 1;
    colors[u] = color;
    for(auto el:a[u]){
        if(!visited[el]){
            dfs(el, !color);
        }
    }
}

int explore(){
    memset(colors, 0, sizeof colors);
    memset(visited, 0, sizeof visited);
    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs(i, 1);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j] && colors[i] == colors[j]) return 0;
        }
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int u, v;
    while(cin >> n, n){
        memset(dist, 0, sizeof dist);
        a.clear(); a.resize(n+1);
        while(cin >> u >> v, u){
            a[u].push_back(v);
            a[v].push_back(u);
            dist[u][v] = dist[v][u] = 1;
        }
        int bipart = explore();
        if(bipart) cout << "YES\n";
        else cout << "NO\n";
    }
}