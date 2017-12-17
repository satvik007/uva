#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1, n;
    while(cin >> n, n){
        cout << "Case " << cas++ << ": " << (n/2) << "\n";
    }
    return 0;
}