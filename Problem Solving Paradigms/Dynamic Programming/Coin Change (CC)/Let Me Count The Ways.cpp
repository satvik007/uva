#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N = 5, V, coinValue[5] = {1, 5, 10, 25, 50};
ll memo[6][31000];

ll ways(int type, int value) {
    if (value == 0)              return 1;
    if (value < 0 || type == N)  return 0;
    if (memo[type][value] != -1) return memo[type][value];
    return memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    memset(memo, -1, sizeof memo);
    while(cin >> n){
        ll ans = ways(0, n);
        if(ans == 1) cout << "There is only 1 way to produce " << n << " cents change.\n";
        else cout << "There are " << ans << " ways to produce " << n << " cents change.\n";
    }
}
