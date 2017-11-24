#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 100000000

int n, m, visited[2005][2005], dist[2005][2005], x, y;
vi a, b;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void distance(){
    int ans = inf, cx, cy, tx, ty;
    for(int i=0; i<n; i++){
        queue <int> q;
        q.push(a[i]); q.push(a[i+n]);
        dist[a[i]][a[i+n]] = 0;
        while(!q.empty()){
            cx = q.front(); q.pop();
            cy = q.front(); q.pop();
            if(cx > x || cy > y) continue;
            if(visited[cx][cy]) ans = min(ans, dist[cx][cy]);
            if(dist[cx][cy] >= ans) break;
            for(int j=0; j<4; j++){
                tx = cx + dr[j];
                ty = cy + dc[j];
                if(tx >= 0 && ty >= 0 && dist[tx][ty] > dist[cx][cy] + 1){
                    dist[tx][ty] = dist[cx][cy] + 1;
                    q.push(tx); q.push(ty);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        a.resize(2*n);
        memset(visited, 0, sizeof visited);
        x = y = 0;
        for(int i=0; i<2005; i++){
            for(int j=0; j<2005; j++){
                dist[i][j] = inf;
            }
        }
        for(int i=0; i<n; i++){
            cin >> a[i] >> a[i+n];
            dist[a[i]][a[i+n]] = 0;
            x = max(x, a[i]);
            y = max(y, a[i+n]);
        }
        cin >> m;
        b.resize(2*m);
        for(int i=0; i<m; i++){
            cin >> b[i] >> b[i+m];
            visited[b[i]][b[i+m]] = 1;
            x = max(x, b[i]);
            y = max(y, b[i+m]);
        }
        distance();
    }
    return 0;
}