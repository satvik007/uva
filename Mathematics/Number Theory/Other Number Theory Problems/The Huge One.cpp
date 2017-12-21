#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        string a; vi b; int size, u, flag = 1;
        cin >> a >> size; b.resize(size);
        for(int i=0; i<b.size(); i++) cin >> b[i];
        for(auto el:b){
            int res = 1, val = 0;
            for(int i=0; i<a.size(); i++){
                val = (val + res * (a[a.size()-i-1]-'0')) % el;
                res = (res * 10) % el;
            }
            if(val != 0) flag = 0;
        }
        if(flag) cout << a << " - Wonderful.\n";
        else cout << a << " - Simple.\n";
    }
    return 0;
}