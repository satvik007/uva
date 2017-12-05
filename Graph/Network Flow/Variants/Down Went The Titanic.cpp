#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

int x, y, p, n, m, cnt;
int s, t, mf, f, res[2000][2000];
vector <string> a;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void connections(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == '*'){
                res[0][2 + i*m + j] = 1;
                res[2 + i*m + j][2 + n*m + i*m + j] = 1;
                for(int k=0; k<4; k++){
                    x = i + dr[k];
                    y = j + dc[k];
                    if(x < n && y < m && x >= 0 && y >= 0 && a[x][y] != '~'){
                        res[2 + n*m + i*m + j][2 + x*m + y] = 1000;
                    }
                }
            }
            else if(a[i][j] == '#'){
                res[2+i*m+j][1] = p;
                for(int k=0; k<4; k++){
                    x = i + dr[k];
                    y = j + dc[k];
                    if(x < n && y < m && x >= 0 && y >= 0 && a[x][y] != '~'){
                        res[2 + i*m + j][x*m + y + 2] = 1000;
                    }
                }
            }
            else if(a[i][j] == '@'){
                for(int k=0; k<4; k++){
                    x = i + dr[k];
                    y = j + dc[k];
                    if(x < n && y < m && x >= 0 && y >= 0 && a[x][y] != '~'){
                        res[2 + i*m + j][x*m + y + 2] = 1000;
                    }
                }
            }
            else if(a[i][j] == '.'){
                res[i*m + j + 2][2 + i*m + j + n * m] = 1;
                for(int k=0; k<4; k++){
                    x = i + dr[k];
                    y = j + dc[k];
                    if(x < n && y < m && x >= 0 && y >= 0 && a[x][y] != '~'){
                        res[2 + i*m + j + n * m][x*m + y + 2] = 1000;
                    }
                }
            }
        }
    }
}

vi par;

void augment(int v, int minEdge){
    if(v == s) f = minEdge;
    else if(par[v] != -1) {
        augment(par[v], min(minEdge, res[par[v]][v]));
        res[par[v]][v] -= f;
        res[v][par[v]] += f;
    }
}

void EdmondKarp(){
    mf = 0;
    while(true){
        f = 0; par.assign(2000, -1);
        queue <int> q; q.push(s);
        bitset <2000> visited; visited.set(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v=0; v<1820; v++){
                if(res[u][v] > 0 && !visited.test(v)){
                    visited.set(v); q.push(v);
                    par[v] = u;
                }
            }
        }
        augment(t, inf);
        if(!f) break;
        mf += f;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    s = 0; t = 1;
    while(cin >> n >> m >> p){
        a.resize(n); memset(res, 0, sizeof res);
        for(int i=0; i<n; i++) cin >> a[i];
        connections();
        EdmondKarp();
        cout << mf << "\n";
    }
    return 0;
}