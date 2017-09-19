#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int n, m;
vi a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cas = 0;
    while(cin >> n >> m, n||m){
        a.resize(n);
        b.resize(m);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<m; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int u = 0;
        int v = 0;
        int counter = 0;
        int flag = 0;
        for(int i=0; i<n; i++){
            if(u == m) {flag = 1; break;}
            if(b[u] >= a[i]) counter += b[u];
            else i--;
            u++;
        }
        if(flag) cout << "Loowater is doomed!\n";
        else cout << counter << "\n";
    }
    return 0;
}
