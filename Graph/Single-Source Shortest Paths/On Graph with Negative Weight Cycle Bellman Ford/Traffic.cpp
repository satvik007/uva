#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
#define inf 1000000000

int n, m, b[205], q, dist[205];
vector <vector <ii>> a;

int cube(int u, int v){
    int x = b[v] - b[u];
    return x*x*x;
}

void ford(){
    for(int i=0; i<n; i++) dist[i] = inf; dist[0] = 0;
    int current;
    for(int i=0; i<n-1; i++) {
        bool flag = true;
        for(int u=0; u<n; u++){
            for(auto el:a[u]){
                if(dist[el.first] > dist[u] + el.second && dist[u] != inf){
                    dist[el.first] = dist[u] + el.second;
                    flag = false;
                }
            }
        }
        if(flag) break;
    }
    for(int i=0; i<n; i++){
        for(auto el:a[i]){
            if(dist[el.first] > dist[i] + el.second && dist[i] != inf) dist[el.first] = -inf;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v, cas = 1;
    while(cin >> n){
        cout << "Set #" << cas << '\n';
        a.clear(); a.resize(n);
        for(int i=0; i<n; i++) cin >> b[i];
        cin >> m;
        for(int i=0; i<m; i++){
            cin >> u >> v; u--; v--;
            a[u].push_back({v, cube(u, v)});
        }
        ford();
        cin >> q;
        for(int i=0; i<q; i++){
            cin >> u; u--;
            if(dist[u] >= 3 && dist[u] != inf) cout << dist[u] << "\n";
            else cout << "?\n";
        }
        cas++;
    }
    return 0;
}