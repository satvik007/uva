#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, tc, u;
    int counter[105];
    cin >> tc;
    int cas = 1;
    while(tc--){
        cin >> n;
        memset(counter, 0, sizeof counter);
        int flag = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> u;
                counter[u]++;
                if(counter[u] > n){
                    flag = 1;
                }
            }
        }
        cout << "Case " << cas++ << ": ";
        if(flag) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}
