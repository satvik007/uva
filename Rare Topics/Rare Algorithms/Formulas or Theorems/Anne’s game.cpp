#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
typedef vector <int> vi;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    for(int cas = 1; cas <= tc; cas++){
        cout << "Case #" << cas << ": ";
        cpp_int res = 1, n;
        cin >> n;
        for(int i=0; i<n-2; i++){
            res *= n;
        }
        cout << res %  (2000000011) << "\n";
    }
    return 0;
}