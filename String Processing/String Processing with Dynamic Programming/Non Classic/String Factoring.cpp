#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int dp[105][105];
string a;

int dfs(int l, int r){
    if(l == r) return 1;
    if(dp[l][r]) return dp[l][r];
    int &ret = dp[l][r];
    ret = 0xfffffff;
    for(int i=l; i<r; i++) ret = min(ret, dfs(l, i) + dfs(i+1, r));
    int sublen = r - l + 1;
    for(int i=1; i<=sublen; i++){
        if(sublen % i == 0){
            int j, k;
            for(k = l, j = 0; k<=r; k++){
                if(a[k] != a[j+l]) break;
                j++; if(j >= i) j = 0;
            }
            if(k == r+1 && r != l+i-1)
                ret = min(ret, dfs(l, l+i-1));
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> a, a != "*"){
        memset(dp, 0, sizeof dp);
        cout << dfs(0, (int)a.size()-1) << "\n";
    }
    return 0;
}