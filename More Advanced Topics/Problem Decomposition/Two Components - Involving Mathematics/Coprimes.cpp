#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int MCD[105][105];
int s, sz;
int a[30];

void generate(int n, int m, int mn){
    if(n == sz){
        if(m == 0){
            for(int i=0; i<sz; i++){
                cout << a[i];
                if(i < sz-1) cout << " ";
                else cout << "\n";
            }
        }
        return;
    }
    bool valid;
    for(int i=mn; i*(sz-n) <= m; i++){
        valid = true;
        for(int j=0; j<n; j++){
            if(MCD[a[j]][i] != 1)
                valid = false;
        }
        if(!valid) continue;
        a[n] = i;
        generate(n+1, m-i, i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for(int i = 1; i <= 100; i++){
        for(int j = i; j <= 100; j++){
            MCD[i][j] = __gcd(i, j);
        }
    }
    int tc; cin >> tc;
    int cas = 1;
    while(tc--){
        cin >> s >> sz;
        cout << "Case " << cas++ << ":\n";
        generate(0, s, 1);
    }
    return 0;
}