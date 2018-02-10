#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define mod 10000000000000007

cpp_int pow(ll b, ll p){
    cpp_int res = 1, a = b;
    while(p){
        if(p & 1){
            res =  (res * a) % mod;
        }
        a = (a * a) % mod;
        a %= mod;
        p >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    ll n, m, p, q;
    while(tc--){
        cin >> p >> q;
        n = (p*q)/2;
        m = p*q - n;
        cout << (pow(n, m-1)*pow(m, n-1)) % mod << "\n";
    }
    return 0;
}