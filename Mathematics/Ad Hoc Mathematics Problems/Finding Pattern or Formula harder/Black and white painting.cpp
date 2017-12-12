#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m, c;
    while(cin >> n >> m >> c, n){
        if(c == 0) {
            cout << ((n-7)*(m-7)/2) << "\n";
        } else {
            cout << ((n-7)*(m-7)+1)/2 << "\n";
        }
    }
    return 0;
}