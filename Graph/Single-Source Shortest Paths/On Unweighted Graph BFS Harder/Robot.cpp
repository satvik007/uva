#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef map <string, int> msi;

int n, m, b[60][60];
bool a[60][60][4];
msi map1;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct robot{
    int x, y, time, dir;
    robot(int p, int q, int r, int s) :x(p),y(q), time(r), dir(s) {}
};

bool valid (int x, int y){
    if(x <= 0 || y <= 0 || x >= n || y >= m) return false;
    if(b[x][y] || b[x-1][y] || b[x-1][y-1] || b[x][y-1]) return false;
    return true;
}

int explore(){
    queue <robot> q;
    int sx, sy, ex, ey; string direct;
    cin >> sx >> sy >> ex >> ey >> direct;
    if(valid(sx, sy)){
        a[sx][sy][map1[direct]] = true;
        q.push(robot(sx, sy, 0, map1[direct]));
    }
    while(!q.empty()){
        robot v = q.front(); q.pop();
        if(v.x == ex && v.y == ey) return v.time;
        if(!a[v.x][v.y][(v.dir+1)%4]){
            q.push(robot(v.x, v.y, v.time+1, (v.dir+1)%4));
            a[v.x][v.y][(v.dir+1)%4] = true;
        }
        if(!a[v.x][v.y][(v.dir+3)%4]){
            q.push(robot(v.x, v.y, v.time+1, (v.dir+3)%4));
            a[v.x][v.y][(v.dir+3)%4] = true;
        }
        for(int i=1; i<=3; i++){
            if(valid(v.x + dr[v.dir]*i, v.y + dc[v.dir]*i)){
                if(a[v.x + dr[v.dir]*i][v.y + dc[v.dir]*i][v.dir]) continue;
                a[v.x + dr[v.dir]*i][v.y + dc[v.dir]*i][v.dir] = true;
                q.push(robot(v.x + dr[v.dir]*i, v.y + dc[v.dir]*i, v.time+1, v.dir));
            }
            else break;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    map1["north"]=0; map1["east"]=1; map1["south"]=2; map1["west"]=3;
    while(cin >> n >> m, n||m){
        memset(a, false, sizeof a);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++){
                cin >> b[i][j];
            }
        }
        int ans = explore();
        cout << ans << endl;
    }
    return 0;
}