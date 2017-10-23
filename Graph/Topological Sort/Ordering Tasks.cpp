#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
vector <vi> a;
int visited[105];
vi ans;
void dfs(int u){
    visited[u] = 1;
    for(auto el:a[u]){
        if(!visited[el]) dfs(el);
    }
    ans.push_back(u);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int u, v;
    while(cin >> n >> m, n){
        a.clear(); a.resize(n+1);
        ans.clear();
        for(int i=0; i<m; i++){
            cin >> u >> v;
            a[u].push_back(v);
        }
        memset(visited, 0, sizeof visited);
        for(int i=1; i<=n; i++){
            if(!visited[i]) dfs(i);
        }
        cout << ans[n-1];
        for(int i=1; i<n; i++) cout << " " << ans[n-i-1]; cout << "\n";

    }
}