#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
#define inf 100000000


int n, m, k;
int a[1005][1005], dist[1005][1005];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool valid(int x, int y){
    if(x < 0 || x >=n || y<0 || y>=m) return false;
    if(a[x][y]) return false;
    return true;
}
void bfs(){
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    queue <ii> q;
    a[sx][sy] = 1;
    dist[sx][sy] = 0;
    q.push({sx, sy});
    ii temp;
    while(!q.empty()){
        ii v = q.front(); q.pop();
        if(v.first == ex && v.second == ey) break;
        for(int i=0; i<4; i++){
            if(valid(v.first+dr[i], v.second+dc[i])){
                temp = make_pair(v.first+dr[i], v.second+dc[i]);
                a[v.first+dr[i]][v.second+dc[i]] = 1;
                q.push(temp);
                dist[v.first+dr[i]][v.second+dc[i]] = dist[v.first][v.second] + 1;
            }
        }
    }
    cout << dist[ex][ey] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int u, v, size;
    while(cin >> n >> m, n||m){
        cin >> k;
        memset(a, 0, sizeof a);
        for(int i=0; i<k; i++){
            cin >> u >> size;
            for(int j=0; j<size; j++){
                cin >> v;
                a[u][v] = 1;
            }
        }
        bfs();
    }
    return 0;
}
