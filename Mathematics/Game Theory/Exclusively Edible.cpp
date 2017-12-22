#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int tc, m, n, r, c;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    while(tc--){
        cin >> m >> n >> r >> c;
        if(((r) ^ (m - r - 1) ^ (c) ^ (n - c - 1)) == 0) cout << "Hansel\n";
        else cout << "Gretel\n";
    }
    return 0;
}