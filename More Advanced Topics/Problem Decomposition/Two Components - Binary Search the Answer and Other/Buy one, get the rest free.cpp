#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

struct Data{
    int u, v, c, p, e;
    bool operator < (Data &y){
        return p < y.p;
    }
};

int n, m, d;
int day1[40], total, s, t, mf, f;
Data a[1010];
int res[400][400];

vi p;

void augment(int v, int minEdge){
    if(v == s) f = minEdge;
    else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}
void edmondKarp(){
    mf = 0;
    while(true){
        p.assign(400, -1); f = 0;
        queue <int> q; q.push(s);
        bitset <400> visited; visited.set(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v=0; v < 5+(d+1)*n; v++){
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

bool solve(int mid){
    s = 0, t = 1;
    memset(res, 0, sizeof res);
    for(int i=0; i<n; i++){
        res[0][2 + i*(d+1)] += day1[i];
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<=d; j++){
            res[2 + i*(d+1) + j - 1][2 + i*(d+1)+j] = inf;
        }
    }
    for(int i=0; i<=d; i++){
        res[2 + (n-1)*(d+1) + i][1] = inf;
    }
    for(int i=0; i<=mid; i++){
        res[2 + a[i].u * (d+1) + a[i].e][2 + a[i].v * (d+1) + a[i].e + 1] += a[i].c;
    }
    edmondKarp();
    return mf == total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc, cas = 1; cin >> tc;
    while(tc--){
        cin >> n >> d >> m;
        for(int i=0; i<m; i++){
            cin >> a[i].u >> a[i].v >> a[i].c >> a[i].p >> a[i].e;
            a[i].u--; a[i].v--;
        }
        sort(a, a+m);
        total = 0;
        for(int i=0; i<n; i++){
            cin >> day1[i]; total += day1[i];
        }
        if(total == day1[n-1]){
            cout << "Case #" << cas++ << ": 0\n"; continue;
        }else if(m == 0) {
            cout << "Case #" << cas++ << "Impossible\n"; continue;
        }
        int lo = 0, mid, hi = m - 1;
        int ans = m;
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            if(solve(mid)) hi = mid - 1, ans = min(ans, mid);
            else lo = mid + 1;
        }
        cout << "Case #" << cas++ << ": ";
        if(ans == m) {
            cout << "Impossible\n";
        }else cout << a[ans].p << "\n";
    }
    return 0;
}