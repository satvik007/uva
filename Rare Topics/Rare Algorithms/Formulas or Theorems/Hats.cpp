#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int der[14];
int fac[14];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    der[0] = 1; der[1] = 0;
    int res = 1;
    fac[0] = fac[1] = 1;
    for(int i=2; i<13; i++){
        der[i] = (i-1) * (der[i-1] + der[i-2]);
        fac[i] = res = res * i;
    }
    int tc; cin >> tc;
    for(int cas = 1; cas <= tc; cas++){
        int n; cin >> n;
        cout << der[n] << "/" << fac[n] << "\n";
    }
    return 0;
}