#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int tc, n, m;
vector <string> a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    while(tc--){
        cin >> n >> m; a.resize(m);
        for(int i=0; i<m; i++) cin >> a[i];
        int counter = 0;
        for(int i=1; i<m; i++){
            string u = a[i-1];
            string v = a[i];
            for(int j=n; j>0; j--){
                string p = u.substr(n-j);
                if(v.find(p) == 0){
                    counter += j; break;
                }
            }
        }
        cout << n * m - counter << endl;
    }
    return 0;
}