#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n;
vector <vi> a;
int dp[1005][3];

int MVC(int u, int flag, int parent){
    if(dp[u][flag] != -1)
        return dp[u][flag];
    if(a[u].size() == 1 && parent != -1)
        return dp[u][flag] = flag;
    int ans = flag;
    if(flag){
        for(auto v:a[u]){
            if(v != parent)
                ans += min(MVC(v, 0, u), MVC(v, 1, u));
        }
    }else{
        for(auto v:a[u]){
            if(v != parent)
                ans += MVC(v, 1, u);
        }
    }
    return dp[u][flag] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        if(n == 1){
            cin >> n;
            cout << 1 << "\n";
            continue;
        }
        int u;
        a.resize(n);
        for(int i=0; i<n; i++){
            cin >> u; a[i].resize(u);
            for(int j=0; j<u; j++){
                cin >> a[i][j]; a[i][j]--;
            }
        }
        memset(dp, -1, sizeof dp);
        int ans = min(MVC(0, 0, -1), MVC(0, 1, -1));
        cout << ans << "\n";
    }
    return 0;
}