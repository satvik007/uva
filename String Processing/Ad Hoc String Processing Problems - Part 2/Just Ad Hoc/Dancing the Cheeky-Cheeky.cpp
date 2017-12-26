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
    int tc; cin >> tc;
    while(tc--){
        string a, u, v, ans; cin >> a;
        for(int i=ceil(a.size()/3.0); i<=a.size()/2; i++){
            u = a.substr(0, i);
            if(a.substr(i, i) == u){
                break;
            }
        }
        for(int i=(a.size() % u.size()), cnt = 0; cnt < 8; cnt++, i = (i + 1) % u.size()){
            cout << u[i];
        }
        cout << "...\n";
    }
    return 0;
}