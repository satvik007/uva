#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

class Iceberg{
public:
    int x, y, cur, max1;
};

int tc, n, mf, f, total, s, t, res[205][205], edges[205][205];
double d;
vector <Iceberg> a;
vi p;

bool dist(int i, int j){
    int x = a[i].x - a[j].x;
    int y = a[i].y - a[j].y;
    return (x*x + y*y <= d*d);
}
void augment(int v, int minEdge){
    if(v == s) f = minEdge;
    else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}
void EdmondKarp(){
    mf = 0;
    while(true){
        f = 0; p.assign(205, -1);
        queue <int> q; q.push(s);
        bitset <205> visited; visited.set(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v=0; v<=2*n+2; v++){
                if(res[u][v] > 0 && !visited.test(v)){
                    visited.set(v); q.push(v);
                    p[v] = u;
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
    vi ans;
    cin >> tc;
    s = 0; t = 1;
    while(tc--){
        cin >> n >> d;
        a.resize(n); ans.clear(); total = 0;
        for(int i=0; i<n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].cur >> a[i].max1;
            total += a[i].cur;
        }
        memset(edges, 0, sizeof edges);
        for(int i=0; i<n; i++){
            edges[0][i+2] = a[i].cur;
            edges[i+2][i+n+2] = a[i].max1;
            for(int j=0; j<n; j++){
                if(dist(i, j)) edges[i+n+2][j+2] = inf;
            }
        }
        for(int i=0; i<n; i++){
            for(int k=0; k<=2*n+2; k++) for(int j=0; j<=2*n+2; j++) res[k][j] = edges[k][j];
            res[i+2][1] = inf;
            EdmondKarp();
            //cout << mf << " " << total << endl;
            if(mf == total) ans.push_back(i);
        }
        if(ans.empty()) cout << "-1\n";
        else {
            for(int i=0; i<ans.size()-1; i++) cout << ans[i] << " ";
            cout << ans[ans.size()-1] << "\n";
        }
    }
    return 0;
}