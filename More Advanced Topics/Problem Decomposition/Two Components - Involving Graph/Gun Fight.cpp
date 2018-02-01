#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

double DEG_to_RAD(double d) {
    return d * PI / 180.0;
}
double RAD_to_DEG(double r) {
    return r * 180.0 / PI;
}
struct point { double x, y, r;   // only used if more precision is needed
    point() { x = y = 0.0; }                      // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};
struct vec { double x, y;  // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {} };
vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y); }
double dist(point p1, point p2) {                // Euclidean distance
    return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double
double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);    // multiply theta with PI / 180.0
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}


point a[305], b[305], c[305];

int n, m, total;
int id1, id2, k;
point sp1, sp2;
double theta = 7.777777;

int check[305][305], visited[305], match[305];

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
int solve(){
    memset(check, 0, sizeof check);
    int mcbm = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(hypot(a[i].x - b[j].x, a[i].y - b[j].y) <= k - EPS){
                if(n < m){
                    if(a[i].r > b[j].r)
                        check[i][j] = 1;
                }else {
                    if(a[i].r < b[j].r)
                        check[i][j] = 1;
                }
            }
        }
    }
    memset(match, -1, sizeof match);
    for(int i=0; i<n; i++){
        memset(visited, 0, sizeof visited);
        mcbm += augment(i);
    }
    return mcbm;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> total, total){
        for(int i=0; i<total; i++){
            cin >> c[i].x >> c[i].y >> c[i].r;
            rotate(c[i], theta);
        }
        cin >> id1 >> id2 >> k;
        sp1 = c[id1-1], sp2 = c[id2 - 1];
        n = 0, m = 0;
        for(int i=0; i<total; i++){
            if(c[i].r == 0) continue;
            if(cross(toVec(sp1, sp2), toVec(sp1, c[i])) > -EPS)
                a[n++] = c[i];
            else
                b[m++] = c[i];
        }
        int ans = solve();
        cout << "Case " << cas++ << ": " << ans << "\n";
    }

    return 0;
}