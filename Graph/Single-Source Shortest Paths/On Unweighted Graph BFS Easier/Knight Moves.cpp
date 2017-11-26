#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 100000000
int fx, fy, ex, ey, dist[10][10];

int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(){
    queue <int> q;
    q.push(fx); q.push(fy);
    for(int i=0; i<10; i++) for(int j=0; j<10; j++) dist[i][j] = inf;
    dist[fx][fy] = 0;
    int cx, cy, tx, ty;
    while(!q.empty()){
        cx = q.front(); q.pop();
        cy = q.front(); q.pop();
        if(cx == ex && cy == ey) break;
        for(int i=0; i<8; i++){
            tx = cx + dr[i];
            ty = cy + dc[i];
            if(tx >= 0 && ty >= 0 && tx < 8 && ty < 8 && dist[tx][ty] > dist[cx][cy] + 1){
                dist[tx][ty] = dist[cx][cy] + 1;
                q.push(tx); q.push(ty);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a, b;
    while(cin >> a >> b){
        fx = a[0]-'a'; ex = b[0]-'a';
        fy = a[1]-'1'; ey = b[1]-'1';
        bfs();
        cout << "To get from " << a << " to " << b << " takes " << dist[ex][ey] << " knight moves.\n";
    }
    return 0;
}