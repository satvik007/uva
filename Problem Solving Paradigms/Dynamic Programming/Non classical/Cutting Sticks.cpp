#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 100000000
int N, K;
int dp[105][105];
int cuts[60];

int cut(int left, int right){
    if(left + 1 == right) return 0;
    if(dp[left][right] != -1) return dp[left][right];
    int ans = inf;
    for(int i=left+1; i<right; i++){
        ans = min(ans, cut(left, i) + cut(i, right) + (cuts[right]-cuts[left]));
    }
    return dp[left][right] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> N, N){
        cin >> K;
        cuts[0] = 0;
        for(int i=1; i<=K; i++) cin >> cuts[i];
        cuts[K+1] = N;
        memset(dp, -1, sizeof dp);
        int ans = cut(0, K+1);
        cout << "The minimum cutting is " << ans << ".\n";
    }
    return 0;
}
