#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define eps 1e-6

double W[105][105];
int n, m;
int mx[105], my[105];
double lx[105], ly[105];
double x[105], y[105];

int hungary(int nd){
    int i;
    x[nd] = 1;
    for(i=1; i<=m; i++){
        if(y[i] == 0 && fabs(W[nd][i] - lx[nd] - ly[i]) < eps){
            y[i] = 1;
            if(my[i] == 0 || hungary(my[i])){
                my[i] = nd;
                return 1;
            }
        }
    }
    return 0;
}
double KM(){
    int i, j, k;
    double d;
    memset(mx, 0, sizeof mx);
    memset(my, 0, sizeof my);
    memset(lx, 0, sizeof lx);
    memset(ly, 0, sizeof ly);
    for(i=1; i<=n; i++){
        for(j=1, lx[i] = W[i][j]; j<=m; j++){
            lx[i] = lx[i] > W[i][j] ? lx[i] : W[i][j];
        }
    }
    for(i=1; i<=n; i++){
        while(true){
            memset(x, 0, sizeof x);
            memset(y, 0, sizeof y);
            if(hungary(i))
                break;
            d = 0xfffffff;
            for(j=1; j<=n; j++){
                if(x[j]){
                    for(k=1; k<=m; k++){
                        if(!y[k])
                            d = d < lx[j] + ly[k] - W[j][k] ?
                                d : lx[j] + ly[k] - W[j][k];
                    }
                }
            }
            if(d == 0xfffffff)
                break;
            for(j=1; j<=n; j++)
                if(x[j])
                    lx[j] -= d;
            for(j=1; j<=m; j++)
                if(y[j])
                    ly[j] += d;
        }
    }
    double res = 0;
    for(i=1; i<=m; i++){
        if(my[i])
            res += W[my[i]][i];
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << setprecision(2) << fixed;
    while(cin >> n >> m && n||m){
        int i, j;
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                cin >> W[i][j];
                W[i][j] *= -1;
            }
        }
        cout << (-KM()/n + eps) << "\n";
    }
    return 0;
}