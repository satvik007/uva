#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9

int n, r;
double b, v, e, f;
int a[105];
double dp[105][105];

double solve(int pos, int last){
    auto index = (int)(lower_bound(a, a+n, pos) - a);
    if(a[index] == pos){
        if(index == n-1) return 0;
        if(dp[index][last] != 0) return dp[index][last];
        double val, ans;
        if(pos - a[last] < r){
            val = 1/(v - f*(r - pos + a[last]));
        }else{
            val = 1/(v - e*(pos-a[last] - r));
        }
        ans = val + solve(pos+1, last);
        if(r > 0){
            val = 1/(v - f*r);
        }else{
            val = 1/(v + e*r);
        }
        ans = min(ans, b + val + solve(pos+1, index));
        return dp[index][last] = ans;
    }else{
        double val;
        if(pos - a[last] < r){
            val = 1/(v - f*(r - pos + a[last]));
        }else{
            val = 1/(v - e*(pos-a[last] - r));
        }
        return val + solve(pos+1, last);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << fixed << setprecision(4);
    while(cin >> n, n){
        a[0] = 0; n++;
        for(int i=1; i<n; i++) cin >> a[i];
        cin >> b;
        cin >> r >> v >> e >> f;
        memset(dp, 0, sizeof dp);
        double ans = solve(0, 0);
        cout << ans << "\n";
    }
    return 0;
}