#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

int n, m;
int a[20][20], odd[20];

void floyd(){
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}
int dp[1<<16];
int build(int pn, int ot){
    if(pn == 0)
        return 0;
    if(dp[pn] != -1)
        return dp[pn];
    int temp;
    dp[pn] = inf;
    for(int i=0; i<ot; i++){
        if(pn & (1<<i)){
            for(int j=i+1; j<ot; j++){
                if(pn & (1<<j)){
                    temp = build(pn - (1<<i) - (1<<j), ot);
                    dp[pn] = min(dp[pn], temp + a[odd[i]][odd[j]]);
                }
            }
            break;
        }
    }
    return dp[pn];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v, w;
    while(cin >> n >> m){
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                a[i][j] = inf;
        int sum = 0, deg[16] = {};
        while(m--){
            cin >> u >> v >> w;
            u--; v--;
            a[u][v] = min(a[u][v], w);
            a[v][u] = min(a[v][u], w);
            deg[u]++, deg[v]++;
            sum += w;
        }
        floyd();
        int ot = 0;
        for(int i=0; i<n; i++){
            if(deg[i] & 1)
                odd[ot++] = i;
        }
        memset(dp, -1, sizeof dp);
        cout << (sum + build((1<<ot)-1, ot)) << "\n";
    }
    return 0;
}