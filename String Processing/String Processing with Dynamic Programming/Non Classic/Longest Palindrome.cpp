#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string a;
int dp[1000+5][1000+5];

int solve(int l, int r){
    if(l == r) return 1;
    if(l + 1 == r) return (a[l] == a[r] ? 2 : 1);
    if(dp[l][r]) return dp[l][r];
    if(a[l] == a[r]) return dp[l][r] = 2 + solve(l+1, r-1);
    else return dp[l][r] = max(solve(l, r-1), solve(l+1, r));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc; cin.ignore();
    while(tc--){
        getline(cin, a); memset(dp, 0, sizeof dp);
        if(a.empty()) cout << "0\n";
        else cout << solve(0, (int)a.size()-1) << "\n";
    }
    return 0;
}