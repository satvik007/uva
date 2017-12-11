#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc, n;
vi a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    int cas = 1;
    while(tc--){
        cin >> n; a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        cout << "Case " << cas++ << ": ";
        cout << a[n/2] << "\n";
    }
    return 0;
}