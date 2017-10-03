#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, x, t, k, m;
int p[105];
int f[105];
int dp[105][23][1105];

int solve(int id, int money, int s){
    if(ceil(money*1.1L) > m || s > 2*(n+1)) return -1000000000;
    if(ceil(money*1.1L) == m || s == 2*(n+1) || id == k) return 0;
    if(dp[id][s][money] != -1) return dp[id][s][money];
    return dp[id][s][money] = max(solve(id+1, money, s), max(f[id] +
    solve(id+1, money+p[id], s+1), 2*f[id] + solve(id+1, money + 2*p[id], s+2)));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> n >> x >> t >> k, n||x||t||k){
        for(int i=0; i<k; i++){
            cin >> p[i];
            int counter = 0;
            int temp;
            for(int j=0; j<n+1; j++){
                cin >> temp;
                counter += temp;
            }
            f[i] = counter;
        }
        m = (n+1)*x;
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, t*(n+1), 0);
        cout << fixed << setprecision(2) << (1.0L*ans)/(n+1) << "\n";
    }
}