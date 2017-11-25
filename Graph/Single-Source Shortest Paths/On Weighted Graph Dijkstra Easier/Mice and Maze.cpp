#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 100000000

int n, e, t, tim, m;
int dist[105][105];

void dijkstra(){
    for(int k=0; k<n; k++) for(int i=0; i<n; i++) for(int j=0; j<n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int counter = 0;
    for(int i=0; i<n; i++){
        if(dist[i][e] <= tim || (e == i)) counter++;
    }
    cout << counter << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v, w;
    cin >> t;
    while(t--){
        cin >> n >> e >> tim >> m; e--;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) dist[i][j] = inf; dist[i][i] = 0;
        }
        for(int i=0; i<m; i++){
            cin >> u >> v >> w;
            u--; v--;
            dist[u][v] = w;
        }
        dijkstra();
        if(t) cout << "\n";
    }
    return 0;
}