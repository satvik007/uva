#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc, cas=1; cin >> tc;
    while(tc--){
        string a; cin >> a;
        int b[3+3]; memset(b, 0, sizeof b);
        int res = 0;
        for(int i=0; i<a.size(); i++){
            b[(a[i]-'0') % 3]++; res += a[i]-'0';
        }
        cout << "Case " << cas++ << ": ";
        if(res % 3 && b[res % 3] != 0) cout << (b[0] % 2 ? "T" : "S") << "\n";
        else cout << (b[0] % 2 ? "S" : "T") << "\n";
    }
    return 0;
}