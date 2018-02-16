#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int solve(int n, int k){
    if(n == 1)
        return 0;
    return (solve(n-1, k) + k) % n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    int n, k;
    int cas = 1;
    while(tc--){
        cin >> n >> k;
        cout << "Case " << cas++ << ": " << solve(n, k) + 1 << "\n";
    }
    return 0;
}