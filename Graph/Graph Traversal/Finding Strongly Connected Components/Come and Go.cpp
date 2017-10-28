#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define UNVISITED -1
int n, m;
vector <vi> a;
vi dfs_num, dfs_low, visited;
int cool, counter;
stack <int> S;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = cool++; // dfs_low[u] <= dfs_num[u]
    S.push(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (auto v:a[u]) {
        if (dfs_num[v] == UNVISITED){
            tarjanSCC(v); if(counter>1) return;
        }

        if (visited[v]) // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); }
    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
        int flag = 1;
        counter++;
        if(counter > 1) return;
        while (true) {
            int v = S.top(); S.pop(); visited[v] = 0;
            if (u == v) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int u, v, w;
    while(cin >> n >> m, n||m){
        a.clear(); a.resize(n);
        for(int i=0; i<m; i++) {
            cin >> u >> v >> w;
            u--; v--;
            a[u].push_back(v);
            if(w-1) a[v].push_back(u);
        }
        dfs_num.assign(n, UNVISITED); dfs_low.assign(n, 0); visited.assign(n, 0);
        counter = cool = 0;
        for (int i = 0; i < n; i++){
            if (dfs_num[i] == UNVISITED)
                tarjanSCC(i);
            if(counter > 1) break;
        }
        if(counter-1) cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}
