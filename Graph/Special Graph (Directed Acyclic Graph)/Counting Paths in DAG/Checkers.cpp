#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9
#define modulo (ll)1000007

int tc, n, fx, fy;
vector <string> a;
ll memo[105][105];

ll solve(int x, int y){
    if(x == 0) return 1;
    if(memo[x][y] != -1) return memo[x][y];
    ll ans = 0;
    if(y > 0){
        if(a[x-1][y-1] == '.') ans += solve(x-1, y-1);
        else if(x > 1 && y > 1 && a[x-2][y-2] == '.') ans += solve(x-2, y-2);
    }
    if(y < n-1){
        if(a[x-1][y+1] == '.') ans += solve(x-1, y+1);
        else if(x > 1 && y < n-2 && a[x-2][y+2] == '.') ans += solve(x-2, y+2);
    }
    return memo[x][y] = ans %= modulo;;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    int cas = 1;
    while(tc--){
        memset(memo, -1, sizeof memo);
        cin >> n; a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int flag = 0;
        for(int i=0; i<n && !flag; i++) {
            for(int j=0; j<n; j++){
                if(a[i][j] == 'W') {
                    fx = i; fy = j; flag = 1; break;
                }
            }
        }
        ll ans = solve(fx, fy);
        cout << "Case " << cas++ << ": " << (ans % modulo) << "\n";
    }
    return 0;
}