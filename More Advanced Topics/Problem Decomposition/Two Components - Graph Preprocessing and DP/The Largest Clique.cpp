#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn 1010

int n, m;
int dfs_num[maxn], dfs_low[maxn], visited[maxn], scc[maxn];
stack <int> s;
int numSCC, cool, counter;
vector <vi> a;

void init(){
    memset(dfs_num, -1, sizeof dfs_num);
    memset(dfs_low, 0, sizeof dfs_low);
    memset(visited, 0, sizeof visited);
    cool = numSCC = 0;
}
void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = cool++;
    s.push(u);
    visited[u] = 1;
    for(auto v:a[u]){
        if(dfs_num[v] == -1)
            tarjanSCC(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        ++numSCC;
        while(true){
            int v = s.top(); s.pop(); visited[v] = 0;
            scc[v] = numSCC;
            if(u == v) break;
        }
    }
}

int dp[maxn], w[maxn];
vector <vi> gg;

int solve(int u){
    if(dp[u])
        return dp[u];
    dp[u] = w[u];
    for(auto v:gg[u])
        dp[u] = max(dp[u], w[u] + solve(v));
    return dp[u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m; a.clear(); a.resize(n);
        int u, v;
        for(int i=0; i<m; i++){
            cin >> u >> v; u--; v--;
            a[u].push_back(v);
        }
        init();
        for(int i=0; i<n; i++)
            if(dfs_num[i] == -1)
                tarjanSCC(i);
        memset(dp, 0, sizeof dp);
        memset(w, 0, sizeof w);
        for(int i=0; i<n; i++)
            w[scc[i]]++;
        gg.clear(); gg.resize(maxn);
        for(int u=0; u<n; u++){
            for(auto v:a[u]){
                if(scc[v] != scc[u])
                    gg[scc[u]].push_back(scc[v]);
            }
        }
        for(int i=1; i<=numSCC; i++)
            if(!dp[i])
                solve(i);
        int ans = *max_element(dp+1, dp+numSCC+1);
        cout << ans << "\n";
    }
    return 0;
}