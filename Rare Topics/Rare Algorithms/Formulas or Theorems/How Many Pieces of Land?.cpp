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
    cpp_int n, ans;
    while(tc--){
        cin >> n;
        ans = 24 + n * (-18 + n * (23 + n * (-6 + n)));
        ans /= 24;
        cout << ans << "\n";
    }
    return 0;
}