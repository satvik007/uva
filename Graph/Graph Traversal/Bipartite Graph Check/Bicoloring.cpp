#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m, colors[205], visited[205];
vector <vi> a;
int mat[205][205];

void dfs(int u){
    for(int i=0; i<a[u].size(); i++){
        if(!visited[a[u][i]]){
            visited[a[u][i]] = 1;
            colors[a[u][i]] = !colors[u];
            dfs(a[u][i]);
        }
    }
}
int traverse(){
    memset(colors, -1, sizeof colors);
    memset(visited, 0, sizeof visited);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = 1;
            colors[i] = 0;
            dfs(i);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] && colors[i] == colors[j]) return 0;
        }
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        cin >> m;
        int u, v;
        a.clear(); a.resize(n);
        memset(mat, 0, sizeof mat);
        for(int i=0; i<m; i++){
            cin >> u >> v;
            mat[u][v] = mat[v][u] = 1;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        int ans = traverse();
        if(ans) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}
