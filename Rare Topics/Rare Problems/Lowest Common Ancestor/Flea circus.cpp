#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

const int N = 5005;

int n, path[N], pn;
vi g[N];

bool dfs(int u, int e, int fa){
    path[pn++] = u;
    if(u == e)
        return true;
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(fa == v)
            continue;
        if(dfs(v, e, u))
            return true;
    }
    pn--;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        for(int i=1; i<=n; i++)
            g[i].clear();
        int u, v;
        for(int i=0; i<n-1; i++){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int q;
        cin >> q;
        int s, e;
        while(q--){
            cin >> s >> e;
            pn = 0;
            dfs(s, e, -1);
            if(pn % 2)
                cout << "The fleas meet at " << path[pn/2] << ".\n";
            else{
                int a = path[pn/2-1], b = path[pn/2];
                if(a > b) swap(a, b);
                cout << "The fleas jump forever between " << a << " and " << b << ".\n";
            }
        }
    }

    return 0;
}