#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, x, y;
int parts[20];
bool dp[(1<<15)+5][101];
bool visited[(1<<15)+5][101];
int sum[(1<<15)];

int calc_sum(){
    for(int m=0; m<(1<<n); m++){
        int res = 0;
        int mask = m;
        for(int i=0; mask; i++, mask >>= 1){
            if(mask & 1) res += parts[i];
        }
        sum[m] = res;
    }
}

bool solve(int mask, int y){
    int inverse = ((1<<n)-1) ^ mask;
    if(__builtin_popcount(inverse) == 1) return true;
    bool &ret = dp[mask][y];
    if(visited[mask][y]) return ret;
    visited[mask][y] = true;
    ret = false;
    int col = sum[inverse]/y;
    for(int split = inverse & (inverse - 1); split; split = (split-1) & inverse){
        int split2 = inverse ^ split;
        if(split2 > split) break;
        if(sum[split] % y == 0 && sum[split2] % y == 0)
            ret = ret | (solve(mask | split, y) & solve(mask | split2, y));
        if(sum[split]%col == 0 && sum[split2]%col == 0)
            ret = ret | (solve(mask | split, sum[split2]/col) & solve(mask | split2, sum[split]/col));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> x >> y){
        int cnt = 0;
        for(int i=0; i<n; i++) cin >> parts[i], cnt += parts[i];
        cout << "Case " << cas++ << ": ";
        if(cnt != x * y) {
            cout << "No\n"; continue;
        }
        calc_sum();
        memset(visited, false, sizeof visited);
        bool flag = solve(0, x);
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}