#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, cool, counter;
vector <vi> a;
int ans[105][105];
vi dfs_num, dfs_low, p;

void solve(int u){
    dfs_num[u] = dfs_low[u] = cool++;
    for(auto el:a[u]){
        if(dfs_num[el] == -1){
            p[el] = u;
            solve(el);
            if(dfs_low[el] > dfs_num[u]) ans[u][el] = ans[el][u] = 1, counter++;
            dfs_low[u] = min(dfs_low[u], dfs_low[el]);
        }
        else if(p[u] != el) dfs_low[u] = min(dfs_low[u], dfs_num[el]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cas = 1;
    int u, v, w;
    char c1, c2;
    while(cin >> n){
        if(n == 0){
            cout << "0 critical links\n\n"; continue;
        }
        a.clear(); a.resize(n);
        memset(ans, 0, sizeof ans);
        dfs_num.assign(n, -1);
        dfs_low.assign(n, -1);
        p.resize(n);
        for(int i=0; i<n; i++){
            cin >> u >> c1 >> w >> c2;
            for(int j=0; j<w; j++){
                cin >> v;
                a[u].push_back(v);
            }
        }
        counter = cool = 0;
        for(int i=0; i<n; i++){
            if(dfs_num[i] == -1) solve(i);
        }
        cout << counter << " critical links\n";
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(ans[i][j]){
                    cout << i << " - " << j << "\n";
                }
            }
        }
        cout << "\n";
        cas++;
    }
    return 0;
}
