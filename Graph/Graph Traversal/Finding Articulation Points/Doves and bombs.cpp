#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int n, m;
vector <vi> a;
vi dfs_num, dfs_low, p;
int cool, root, child;
bool visited[10005], art[10005];
vector <ii> ans;

void solve(int u){
    dfs_num[u] = dfs_low[u] = cool++;
    for(auto el:a[u]){
        if(dfs_num[el] == -1){
            p[el] = u;
            if(u == root) child++;
            solve(el);
            if(dfs_low[el] >= dfs_num[u]) art[u] = true;
            dfs_low[u] = min(dfs_low[el], dfs_low[u]);
        }
        else if (p[u] != el) dfs_low[u] = min(dfs_num[el], dfs_low[u]);
    }
}

void dfs(int u){
    visited[u] = true;
    for(auto el:a[u]) if(!visited[el]) dfs(el);
}

bool comp(ii x, ii y){
    if(x.second == y.second) return (x.first < y.first);
    return (x.second > y.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v;
    while(cin >> n >> m, n||m){
        memset(art, false, sizeof art);
        a.clear(); a.resize(n);
        ans.clear();
        dfs_num.assign(n, -1);
        dfs_low.assign(n, -1);
        p.assign(n, 0);
        cool = root = child = 0;
        while(cin >> u >> v, (u+1) || (v+1)){
            a[u].push_back(v);
            a[v].push_back(u);
        }
        solve(root);
        if(child > 1) art[root] = true;
        for(int i=0; i<n; i++){
            if(art[i]){
                memset(visited, false, sizeof visited);
                visited[i] = true;
                int cc = 0;
                for(int j=0; j<n; j++){
                    if(!visited[j]){
                        cc++;
                        dfs(j);
                    }
                }
                ans.push_back({i, cc});
            }
        }
        sort(ans.begin(), ans.end(), comp);
        for(int i=0; i<(int)ans.size() && i<m; i++){
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
        auto k = (int)ans.size();
        for(int i=0; i<n && k<m; i++){
            if(!art[i]){
                k++;
                cout << i << " 1\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
