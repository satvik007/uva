#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf LONG_MAX

int n, m, a[700];
ll memo[700][400];

ll solve(int current, int left){
    if(left < 0) return inf;
    if(current == n) return 0;
    if(memo[current][left] != -1) return memo[current][left];
    ll ans = inf, last = 0;
    for(int i=current; i<n; i++){
        last += a[i];
        ans = min(ans, max(last, solve(i+1, left - 1)));
    }
    return memo[current][left] = ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> m){
        n++; m++;
        memset(memo, -1, sizeof memo);
        for(int i=0; i<n; i++) cin >> a[i];
        cout << solve(0, m) << "\n";
    }
    return 0;
}