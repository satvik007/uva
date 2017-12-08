#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

int n, k, a[100][100], flag;
int memo[80][80][8][5];

// right down left;
int dr[] = {0, 1, 0};
int dc[] = {1, 0, -1};

int solve(int x, int y, int left, int dir){
    if(x < 0 || y < 0 || x >= n || y >= n || left < 0) return -inf;
    if(x == n-1 && y == n-1){
        if(a[x][y] < 0 && left == 0) return -inf;
        else {
            flag = 1; return a[x][y];
        }
    }
    if(memo[x][y][left][dir] != -1) return memo[x][y][left][dir];
    int ans = -inf;
    for(int i=0; i<3; i++){
        if((dir == 0 && i == 2) || (dir == 2 && i == 0)) continue;
        if(a[x][y] < 0) ans = max(ans, a[x][y] + solve(x + dr[i], y + dc[i], left - 1, i));
        else ans = max(ans, a[x][y] + solve(x+dr[i], y + dc[i], left, i));
    }
    return memo[x][y][left][dir] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> k, n||k){
        memset(memo, -1, sizeof memo);
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> a[i][j];
        flag = 0;
        int ans = solve(0, 0, k, 1);
        cout << "Case " << (cas++) << ": ";
        if(!flag) cout << "impossible\n";
        else cout << ans << "\n";
    }
    return 0;
}