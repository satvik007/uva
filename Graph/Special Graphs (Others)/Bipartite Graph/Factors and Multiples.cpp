#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc, n, m;
int a[105], b[105], visited[105], match[105];
int check[105][105];

int augment(int u){
    if(visited[u]) return 0;
    visited[u] = 1;
    for(int v=0; v<m; v++){
        if(check[u][v] && (match[v] == -1 || augment(match[v]))){
            match[v] = u; return 1;
        }
    }
    return 0;
}

void solve(){
    memset(check, 0, sizeof check);
    int mcbm = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i] == 0 && b[j] == 0) check[i][j] = 1;
            if(a[i] == 0) continue;
            else if(b[j] % a[i] == 0) check[i][j] = 1;
        }
    }
    memset(match, -1, sizeof match);
    for(int i=0; i<n; i++){
        memset(visited, 0, sizeof visited);
        mcbm += augment(i);
    }
    cout << mcbm << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    for(int cas = 1; cas <= tc; cas++){
        cin >> n; for(int i=0; i<n; i++) cin >> a[i];
        cin >> m; for(int j=0; j<m; j++) cin >> b[j];
        cout << "Case " << cas << ": ";
        solve();
    }
    return 0;
}