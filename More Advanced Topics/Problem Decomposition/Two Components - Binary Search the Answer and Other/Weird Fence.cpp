#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int num, n, m, k;
struct Data{
    int x, y;
};
Data a[105], b[105];
int check[105][105], visited[105], match[105];

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
bool solve(int mid){
    memset(check, 0, sizeof check);
    int mcbm = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(hypot(a[i].x - b[j].x, a[i].y - b[j].y) <= mid){
                check[i][j] = 1;
            }
        }
    }
    memset(match, -1, sizeof match);
    for(int i=0; i<n; i++){
        memset(visited, 0, sizeof visited);
        mcbm += augment(i);
    }
    //cout << mcbm << "\n";
    return mcbm >= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        cin >> num >> k;
        int u, v;
        string typ;
        n = 0, m = 0;
        for(int i=0; i<num; i++){
            cin >> u >> v >> typ;
            if(typ == "red") a[n].x = u, a[n++].y=v;
            else b[m].x = u, b[m++].y = v;
        }
        int lo = 0, mid, hi = 4000;
        int ans = hi;
        while (lo <= hi){
            mid = lo + (hi - lo)/2;
            if(solve(mid)) hi = mid - 1, ans = min(ans, mid);
            else lo = mid + 1;
        }
        if(ans == 4000){
            cout << "Impossible\n";
        }else cout << ans << "\n";
    }
    return 0;
}