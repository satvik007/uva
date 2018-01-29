#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

int n, m, p, q;
vector <string> a;
vi b;
int dp[1010][110];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void floodfill(int r, int c, char cur, char as){
    if(r < 0 || c < 0 || r >= n || c >= m || a[r][c] != cur) return;
    a[r][c] = as;
    for(int k=0; k<4; k++){
        floodfill(r+dr[k], c+dc[k], cur, as);
    }
}

int solve(int current, int left){
    if(current >= m && left != 0) return inf;
    if(left == 0) return 0;
    if(dp[current][left] != -1) return dp[current][left];
    int ans = inf;
    for(int i=current; i<m; i++){
        ans = min(ans, b[i] + solve(i + q + 1, left - 1));
    }
    return dp[current][left] = ans;
}

void calcBridge(){
    for(int i=0; i<m; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(a[j][i] == '3') cnt++;
            if(a[j][i] == '1') cnt = 0;
            if(a[j][i] == '2') break;
        }
        b[i] = cnt;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> m){
        cin >> p >> q; a.resize(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        floodfill(0, 0, '#', '1');
        floodfill(n-1, 0, '#', '2');
        int x;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(a[j][i] == '2'){
                    x = j - 1; break;
                }
            }
            floodfill(x, i, '.', '3');
        }
        b.assign(m, 0);
        calcBridge();
        memset(dp, -1, sizeof dp);
        int ans = solve(0, p);
        cout << ans << "\n";
    }
    return 0;
}