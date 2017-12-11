#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> r, n||r){
        cout << "Case " << cas++ << ": ";
        if(n > 27*r) cout << "impossible\n";
        else cout << (ceil(n*1.0/r)-1) << "\n";
    }
    return 0;
}