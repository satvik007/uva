#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

struct point{
    int x, y;
};
struct Data{
    int x, y, z;
};

double dist(point a, point b){
    return hypot(a.x - b.x, a.y - b.y);
}

int n, b1, b2;
vector <point> a;
double d[110][110];
double dp[110][110][5];
Data path[110][110][5];

double solve(int p1, int p2, int flag){
    int v = max(p1, p2) + 1;
    if(dp[p1][p2][flag] > -0.5)
        return dp[p1][p2][flag];
    if (v == n-1)
        return d[p1][v] + d[v][p2];
    if(v == b1 || v == b2){
        if(flag == 0){
            double c1 = d[p1][v] + solve(v, p2, 1);
            double c2 = d[p2][v] + solve(p1, v, 2);
            if(c1 <= c2){
                path[p1][p2][flag] = {v, p2, 1};
                return dp[p1][p2][flag] = c1;
            }else{
                path[p1][p2][flag] = {p1, v, 2};
                return dp[p1][p2][flag] = c2;
            }

        }else if(flag == 1){
            path[p1][p2][flag] = {p1, v, 1};
            return dp[p1][p2][flag] = d[p2][v] + solve(p1, v, 1);
        }else{
            path[p1][p2][flag] = {v, p2, 2};
            return dp[p1][p2][flag] = d[v][p1] + solve(v, p2, 2);
        }
    }else{
        double c1 = d[p1][v] + solve(v, p2, flag);
        double c2 = d[p2][v] + solve(p1, v, flag);
        if(c1 <= c2){
            path[p1][p2][flag] = {v, p2, flag};
            return dp[p1][p2][flag] = c1;
        }else{
            path[p1][p2][flag] = {p1, v, flag};
            return dp[p1][p2][flag] = c2;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    cout << fixed << setprecision(2);
    stack <int> s;
    queue <int> q;
    while(cin >> n >> b1 >> b2, n){
        a.resize(n);
        for(int i=0; i<n; i++){
            cin >> a[i].x >> a[i].y;
        }
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                d[i][j] = d[j][i] = dist(a[i], a[j]);
            }
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<4; k++)
                    dp[i][j][k] = -1, path[i][j][k] = {-1, -1, -1};
        cout << "Case " << cas++ << ": ";
        double ans = solve(0, 0, 0);
        cout << ans << "\n";
        int x=0, y=0, z=0;
        Data current;
        while(path[x][y][z].x != -1){
            current = path[x][y][z];
            if(current.y != y)
                s.push(current.y);
            else
                q.push(current.x);
            x = current.x; y = current.y; z = current.z;
        }
        cout << 0 << " ";
        while(!q.empty()){
            cout << q.front() << " "; q.pop();
        } cout << n-1 << " ";
        while(!s.empty()){
            cout << s.top() << " "; s.pop();
        } cout << 0 << "\n";
    }
    return 0;
}