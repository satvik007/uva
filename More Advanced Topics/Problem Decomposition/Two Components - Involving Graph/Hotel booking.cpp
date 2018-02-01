#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
#define inf (int)1e9

int n, m, h;
map <int, int> hotels;
int b[105];
vector <vector <ii>> a;
int visited[10005];
int dist[10005];

void dijkstra(int src){
    for(int i=0; i<n; i++) dist[i] = inf;
    dist[src] = 0;
    priority_queue <ii> pq; pq.push({0, src});
    ii uu; int u;
    while(!pq.empty()){
        uu = pq.top(); pq.pop();
        u = uu.second;
        if(dist[u] < uu.first || uu.first > 600) continue;
        for(auto v:a[u]){
            if(dist[v.first] > dist[u] + v.second){
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

void solve() {
    int visited[105] = {0};
    queue <int> p, q; p.push(0); q.push(0);
    int c, dd;
    while(!p.empty()){
        c = p.front(); p.pop();
        dd = q.front(); q.pop();
        dijkstra(c);
        if(dist[n-1] <= 600){
            cout << dd << "\n"; return;
        }
        for(int i=0; i<h; i++){
            if(dist[b[i]] <= 600 && !visited[i]){
                visited[i] = 1;
                p.push(b[i]);
                q.push(dd + 1);
            }
        }
    }
    cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        cin >> h; hotels.clear();
        for(int i=0; i < h; i++){
            cin >> b[i]; b[i]--;
            hotels[b[i]] = 1;
        }
        cin >> m;
        int u, v, w;
        a.clear(); a.resize(n);
        for(int i=0; i<m; i++){
            cin >> u >> v >> w; u--; v--;
            a[u].push_back({v, w});
            a[v].push_back({u, w});
        }
        solve();
    }
    return 0;
}