#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    double n, m, k; // cow, cars, shows
    cout << setprecision(5) << fixed;
    while(cin >> n >> m >> k){
        double a = ((n) / (m + n)) * ((m) / (n + m - k - 1));
        double b = ((m) / (m + n)) * ((m - 1) / (n + m - k - 1));
        cout << a + b << "\n";
    }
    return 0;
}