#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

string name;
int n, m, t;
int a[105][105], b[105][105];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int solve(int x, int y){
    if(b[x][y] != -1) return b[x][y];
    int ans = 1;
    for(int k=0; k<4; k++){
        int nx = x + dr[k];
        int ny = y + dc[k];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] > a[x][y]){
            ans = max(ans, solve(nx, ny)+1);
        }
    }
    return (b[x][y] = ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    while(t--){
        memset(b, -1, sizeof b);
        cin >> name >> n >> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cin >> a[i][j];
        }
        cout << name << ": ";
        int max1 = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(b[i][j] == -1){
                    max1 = max(max1, solve(i, j));
                }
            }
        }
        cout << max1 << "\n";
    }
    return 0;
}