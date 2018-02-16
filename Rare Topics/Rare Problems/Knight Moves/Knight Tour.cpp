#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int dist[1005][1005] = {};
int g[16][16];
void bfs(){
    static int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    static int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    int i, j, k, x, y, tx, ty;
    queue <int> X, Y;
    X.push(0), Y.push(0);
    while(!X.empty()){
        x = X.front(), X.pop();
        y = Y.front(), Y.pop();
        for(i=0; i<8; i++){
            tx = x + dx[i], ty = y + dy[i];
            if(tx < 0 || ty < 0 || tx > 1000 || ty > 1000)
                continue;
            if(dist[tx][ty] == 0){
                dist[tx][ty] = dist[x][y] + 1;
                X.push(tx), Y.push(ty);
            }
        }
    }
    dist[0][0] = 0;
}

int dist2[1005][1005], used[1005][1005] = {};
int bfs2(int x1, int y1, int x2, int y2, int n){
    static int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    static int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    static int cases = 0;
    ++cases;
    int i, j, k, x, y, tx, ty;
    queue <int> X, Y;
    X.push(x1), Y.push(y1);
    dist2[x1][y1] = 0;
    while(!X.empty()){
        x = X.front(), X.pop();
        y = Y.front(), Y.pop();
        if(dist2[x][y] > 30)
            break;
        for(i=0; i<8; i++){
            tx = x + dx[i], ty = y + dy[i];
            if(tx < 1 || ty < 1 || tx > n || ty > n)
                continue;
            if(used[tx][ty] != cases){
                used[tx][ty] = cases;
                dist2[tx][ty] = dist2[x][y] + 1;
                if(tx == x2 && ty == y2)
                    return dist2[tx][ty];
                X.push(tx), Y.push(ty);
            }
        }
    }
    return 0xfffff;
}
int dp[1<<16][16];
int dfs(int state, int last, int n){
    int &ret = dp[state][last];
    if(ret != -1)
        return ret;
    if(state == 0)
        return g[last][0];
    ret = 0xfffffff;
    for(int i=0; i<n; i++){
        if((state >> i) & 1){
            ret = min(ret, dfs(state^(1<<i), i, n)+g[last][i]);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    bfs();
    int tc, cases = 0;
    int n, m;
    int x[16], y[16];
    int i, j, k;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(i=0; i<m; i++)
            cin >> x[i] >> y[i];
        for(i=0; i<m; i++){
            for(j=0; j<m; j++){
                if(abs(x[i]-x[j])+abs(y[i]-y[j])>20)
                    g[i][j] = dist[abs(x[i]-x[j])][abs(y[i]-y[j])];
                else
                    g[i][j] = bfs2(x[i], y[i], x[j], y[j], n);
            }
            g[i][i] = 0;
        }
        memset(dp, -1, sizeof dp);
        int ans = dfs((1<<m)-2, 0, m);
        cout << "Case " << ++cases << ": " << ans << "\n";
    }
    return 0;
}