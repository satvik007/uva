#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf (int)1e9

int n;
int a[105], b[105], c[105][105];
int dp[105][105][3];

int solve(int left, int right, int chance){
    if(left > right) return 0;
    if(dp[left][right][chance] != -1) return dp[left][right][chance];
    int ans = -inf;
    for(int i=left; i<=right; i++){
        ans = max(ans, c[left][i] + solve(i+1, right, !chance));
    }
    for(int i = right; i>=left; i--){
        ans = max(ans, c[i][right] + solve(left, i-1, !chance));
    }
    return dp[left][right][chance] = -ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        for(int i=0; i<n; i++)
            cin >> a[i];
        b[0] = a[0];
        for(int i=1; i<n; i++)
            b[i] = b[i-1] + a[i];
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(i == 0) c[i][j] = b[j];
                else c[i][j] = b[j] - b[i-1];
            }
        }
        memset(dp, -1, sizeof dp);
        int ans = solve(0, n-1, 0);
        cout << (-ans) << "\n";
    }
    return 0;
}