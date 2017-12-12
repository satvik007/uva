#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n, n) {
        int m, i, j = 1;
        for(m = 1, i = 2, j = 1; ; m += i, i += 2, j++) {
            if(abs(m-n) < j)
                break;
        }
        int x = j, y = j;
        if(j&1) {
            if(n > m)
                x -= (n-m);
            else
                y -= (m-n);
        } else {
            if(n > m)
                y -= (n-m);
            else
                x -= (m-n);
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}