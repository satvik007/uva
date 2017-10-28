#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define UNVISITED -1
int n, m;
vector <vi> a, b;
vi dfs_num, dfs_low, visited;
int numSCC, cool, counter;
vi ans;
set <int> map1;
stack <int> S;
void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = cool++; // dfs_low[u] <= dfs_num[u]
    S.push(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (auto v:a[u]) {
        if (dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if (visited[v]) // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); }
        if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
            int flag = 1;
            map1.clear();
            while (true) {
                int v = S.top(); S.pop(); visited[v] = 0;
                map1.insert(v);
                if (u == v) break;
            }
            for(auto el:map1){
                for(auto atom:b[el]){
                    if(map1.find(atom) == map1.end()){
                        flag = 0; break;
                    }
                }
                if(!flag) break;
            }
            if(flag) counter++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, u, v;
    cin >> t;
    while(t--){
        cin >> n >> m;
        a.clear(); a.resize(n);
        b.clear(); b.resize(n);
        for(int i=0; i<m; i++) {
            cin >> u >> v;
            u--; v--;
            a[u].push_back(v);
            b[v].push_back(u);
        }
        dfs_num.assign(n, UNVISITED); dfs_low.assign(n, 0); visited.assign(n, 0);
        counter = cool = numSCC = 0;
        for (int i = 0; i < n; i++)
            if (dfs_num[i] == UNVISITED)
                tarjanSCC(i);
        cout << counter << endl;
    }
    return 0;
}
