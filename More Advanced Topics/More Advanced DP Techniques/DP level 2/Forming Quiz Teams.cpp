#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

#define inf 1e12
int n;
double dp[1000000];

class Data{
public:
    string name;
    int x, y;
    Data(string namea, int xa, int ya){
        name = namea, x = xa, y = ya;
    }
    Data(){}
};
vector <Data> a;

double solve(int mask){
    if((mask ^ ((1<<(2*n))-1)) == 0) return 0;
    if(dp[mask] != 0) return dp[mask];
    double ans = inf;
    for(int i=0; i<2*n; i++){
        if(!(mask & (1<<i))){
            for(int j=0; j<2*n; j++){
                if(!(mask & (1<<j)) && i != j){
                    ans = min(ans, hypot(a[i].x - a[j].x, a[i].y - a[j].y) +
                            solve(mask | (1<<i) | (1<<j)));
                }
            }
        }
    }
    return dp[mask] = ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    cout << fixed << setprecision(2);
    while(cin >> n, n){
        memset(dp, 0, sizeof dp); a.resize(2*n);
        for(int i=0; i<2*n; i++){
            cin >> a[i].name >> a[i].x >> a[i].y;
        }
        double ans = solve(0);
        cout << "Case " << cas++ << ": " << ans << "\n";
    }
    return 0;
}