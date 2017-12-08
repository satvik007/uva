#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9
#define mod 20437

class Data{
public:
    int x, y, dist;
    char cur;
    Data(){}
    Data(int xa, int ya, char cura, int dista)
            : x(xa), y(ya), cur(cura), dist(dista) {}
};

char last;
int n, fx, fy;
vector <string> a;
int visited[12][12][40], dp[12*12*40][12][12][40];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void solve(){
    int tx, ty;
    memset(visited, 0, sizeof visited); memset(dp, 0, sizeof dp);
    queue <Data> q; q.push(Data(fx, fy, 'A', 0));
    dp[0][fx][fy][0] = 1;
    while(!q.empty()){
        Data u = q.front(); q.pop();
        if(visited[u.x][u.y][u.cur-'A']) continue;
        visited[u.x][u.y][u.cur-'A'] = 1;
        if(a[u.x][u.y] == last){
            cout << u.dist << " " << (dp[u.dist][u.x][u.y][u.cur-'A'] % mod) << "\n";
            return;
        }
        int new_paths = dp[u.dist][u.x][u.y][u.cur-'A'];
        if(a[u.x][u.y] == u.cur) a[u.x][u.y] = '.', u.cur++;
        for(int i=0; i<4; i++){
            tx = u.x + dr[i]; ty = u.y + dc[i];
            if(tx >= 0 && ty >= 0 && tx < n && ty < n && !visited[tx][ty][u.cur-'A'] && (a[tx][ty] == '.' || a[tx][ty] == u.cur)){
                dp[u.dist+1][tx][ty][u.cur-'A'] += (new_paths) % mod;
                q.push(Data(tx, ty, u.cur, u.dist+1));
            }
        }
    }
    cout << "Impossible\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n, n){
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        last = 'A';
        for(int i=0; i<n; i++){ for(int j=0; j<n; j++){
                if(a[i][j] >= 'A' && a[i][j] <= 'Z'){
                    if(a[i][j] == 'A') fx = i, fy = j;
                    if(last < a[i][j]) last = a[i][j];
                }
            }
        }
        cout << "Case " << (cas++) << ": ";
        solve();
    }
    return 0;
}