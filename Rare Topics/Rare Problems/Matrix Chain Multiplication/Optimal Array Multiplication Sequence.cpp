#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn 12

int p[maxn], dp[maxn][maxn];
int n, tc;

int kk[maxn][maxn];
int par[maxn][2];

int top_down(int i, int j){
    if(i == j)
        return 0;
    if(dp[i][j] == -1){
        dp[i][j] = INT_MAX;
        for(int k=i; k<j; k++){
            int prev = top_down(i, k) + top_down(k+1, j) + p[i-1]*p[k]*p[j];
            if(prev < dp[i][j]){
                kk[i][j] = k;
                dp[i][j] = prev;
            }
        }
    }
    return dp[i][j];
}

void addpar(int i, int j){
    if(i == j)
        return;
    par[i][0]++, par[j][1]++;
    if(i == j-1)
        return;
    addpar(i, kk[i][j]);
    addpar(kk[i][j]+1, j);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        for(int i=1; i<=n; i++){
            cin >> p[i-1] >> p[i];
        }
        memset(dp, -1, sizeof dp);
        memset(kk, -1, sizeof kk);
        for(int i=2; i<=n; i++)
            dp[i-1][i] = p[i-2] * p[i-1] * p[i];
        top_down(1, n);
        cout << "Case " << ++tc << ": ";
        memset(par, 0, sizeof par);
        addpar(1, n);
        for(int i=1; i<=n; i++){
            if(i != 1) cout << " x ";
            for(int j=0; j<par[i][0]; j++){
                cout << '(';
            }
            cout << "A" << i;
            for(int j=0; j<par[i][1]; j++){
                cout << ")";
            }
        }
        cout << endl;
    }
    return 0;
}