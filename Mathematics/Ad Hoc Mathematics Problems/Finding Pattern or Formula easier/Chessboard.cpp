#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, tc;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    cout << fixed << setprecision(3);
    while(tc--){
        cin >> n;
        if(n > 1) cout << (4 * n - 4) + sqrt(2) * (n - 2) * (n - 2) << "\n";
        else cout << "0.000" << "\n";
        if(tc) cout << "\n";
    }
    return 0;
}