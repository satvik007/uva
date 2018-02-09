#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

struct point{
    int x, y;
    bool operator < (point p){
        if(p.x == x) return y < p.y;
        return x < p.x;
    }
};

double dist(point a, point b){
    return hypot(a.x - b.x, a.y - b.y);
}

int n;
vector <point> a;
double memo[1005][1005];
double d[1005][1005];

double solve(int p1, int p2){
    int v = max(p1, p2) + 1;
    if (v == n-1)
        return d[p1][v] + d[v][p2];
    if (memo[p1][p2] > -0.5)
        return memo[p1][p2];
    return memo[p1][p2] = min(d[p1][v] + solve(v, p2), d[v][p2] + solve(p1, v));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << setprecision(2) << fixed;
    while(cin >> n){
        a.resize(n);
        for(int i=0; i<n; i++){
            cin >> a[i].x >> a[i].y;
        }
        sort(a.begin(), a.end());
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                d[i][j] = d[j][i] = dist(a[i], a[j]);
            }
        }
        memset(memo, -1, sizeof memo);
        double ans = solve(0, 0);
        cout << ans << "\n";
    }
    return 0;
}