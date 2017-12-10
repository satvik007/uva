#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

int n, m, deg[500], res[205][205];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v;
    while(cin >> n >> m){
        memset(deg, 0, sizeof deg);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                res[i][j] = inf;
            }
            res[i][i] = 0;
        }
        for(int i=0; i<m; i++){
            cin >> u >> v;
            res[u][v] = 1;
            res[v][u] = 1;
            deg[u]++; deg[v]++;
        }
        int flag = 0;
        for(int i=0; i<n; i++){
            if(deg[i] % 2) {
                flag = 1; break;
            }
        }
        if(!flag) {
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
                    }
                }
            }
            for(int i=0; i<n && !flag; i++){
                for(int j=0; j<n; j++){
                    if(res[i][j] == inf && deg[i] && deg[j]){
                        flag = 1; break;
                    }
                }
            }
        }
        if(!m) flag = 1;
        if(flag) cout << "Not Possible\n";
        else cout << "Possible\n";
    }


    return 0;
}