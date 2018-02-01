#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m, k;
int lx[1005], rx[1005], ly[1005], ry[1005];
int g[2010][2010], dp[2010][2010];
ll x[4010], y[4010];

map <int, int> Rx, Ry;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> m >> n >> k, m||n||k){
        Rx.clear(); Ry.clear();
        Rx[0] = 1, Ry[0] = 1;
        Rx[n] = 1, Ry[m] = 1;
        for(int i=0; i<k; i++){
            cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
            rx[i]++; ry[i]++;
            Rx[lx[i]] = 1, Ry[ly[i]] = 1;
            Rx[rx[i]] = 1, Ry[ry[i]] = 1;
        }
        int sizex = 0, sizey = 0;
        for(auto it = Rx.begin(); it != Rx.end(); it++){
            it -> second = sizex;
            x[sizex++] = it -> first;
        }
        for(auto it = Ry.begin(); it != Ry.end(); it++){
            it -> second = sizey;
            y[sizey++] = it -> first;
        }
        memset(g, 0, sizeof g);
        memset(dp, 0, sizeof dp);
        for(int i=0; i<k; i++){
            int llx = Rx[lx[i]], rrx = Rx[rx[i]];
            int rry = Ry[ry[i]];
            for(int p=llx+1; p <= rrx; p++){
                g[p][rry] = 1;
            }
        }
        dp[sizex-1][sizey-1] = 1;
        ll ret = 0;
        for(int i = sizex - 1; i > 0; i--){
            for(int j= sizey - 1; j > 0; j--){
                if(g[i][j])
                    continue;
                if(!dp[i][j])
                        ret += (x[i] - x[i-1]) * (y[j] - y[j-1]);
                dp[i-1][j] |= dp[i][j];
                dp[i][j-1] |= dp[i][j];
            }
        }
        cout << "Case " << cas++ << ": " << ret << "\n";
    }
    return 0;
}