#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
vector <vi> a;
int visited[105];

int dfs(int u){
    visited[u] = 1;
    int ans = 1;
    for(auto el:a[u]){
        if(!visited[el]) ans += dfs(el);
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v;
    while(cin >> n, n){
        a.clear(); a.resize(n+1);
        while(cin >> u, u){
            while(cin.peek() != '\n'){
                cin.ignore();
                cin >> v;
                a[u].push_back(v);
                a[v].push_back(u);
            }
        }
        int current;
        int ans = 0;
        for(int i=1; i<=n; i++){
            memset(visited, 0, sizeof visited);
            visited[i] = 1;
            current = dfs(i != 1?1:2);
            if(current < n-1) ans++;
        }
        cout << ans << "\n";
    }
}