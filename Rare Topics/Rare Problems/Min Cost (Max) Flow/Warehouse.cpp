#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int ng[50][50], used[50][50];
int dp[1<<16], W[30][30];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int Bt, Xt, n, m;
char g[50][50];

void bfs(int x, int y){
    memset(used, 0, sizeof used);
    int i, tx, ty;
    queue <int> X, Y;
    X.push(x); Y.push(y);
    while(!X.empty()){
        x = X.front(), X.pop();
        y = Y.front(), Y.pop();
        if(g[x][y] == 'X')
            W[Bt][ng[x][y]] = used[x][y];
        for(i=0; i<4; i++){
            tx = x + dx[i], ty = y + dy[i];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m)
                continue;
            if(g[tx][ty] == '#')
                continue;
            if(used[tx][ty] == 0){
                used[tx][ty] = used[x][y] + 1;
                X.push(tx);
                Y.push(ty);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, i, j, k;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(i=0; i<n; i++){
            cin >> g[i];
        }
        Bt = 0, Xt = 0;
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if(g[i][j] == 'X')
                    ng[i][j] = Xt++;
            }
        }
        for(i=0; i<=Xt; i++)
            for(j=0; j<=Xt; j++)
                W[i][j] = 1<<20;
        for(i=0; i<n; i++)
            for(j=0; j<m; j++){
                if(g[i][j] == 'B'){
                    Bt++;
                    bfs(i, j);
                }
            }
        int mxState = (1<<Xt);
        for(i=0; i<mxState; i++)
            dp[i] = 1<<20;
        dp[0] = 0;
        vi DIGIT[16];
        for(i=0; i<mxState; i++){
            j = __builtin_popcount(i);
            DIGIT[j].push_back(i);
        }
        for(i=1; i<=Bt; i++){
            for(int k1=0; k1<DIGIT[i-1].size(); k1++){
                j = DIGIT[i-1][k1];
                for(k=0; k<Bt; k++){
                    if((j&(1<<k)) == 0){
                        dp[j|(1<<k)] = min(dp[j|(1<<k)], dp[j]+W[i][k]);
                    }
                }
            }
        }
        cout << dp[mxState-1] << "\n";
    }
    return 0;
}