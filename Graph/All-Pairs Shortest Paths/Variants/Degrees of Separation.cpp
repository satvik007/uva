#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef map <string, int> msi;
#define inf 1000000000

int n, m, a[60][60];
msi map1;

void floyd(){
    for(int k=0; k<n; k++) for(int i=0; i<n; i++) for(int j=0; j<n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    int min1 = -1;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) min1 = max(min1, a[i][j]);
    if(min1 == inf) cout << "DISCONNECTED\n\n";
    else cout << min1 << "\n\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas = 1;
    string u, v;
    while(cin >> n >> m, n||m){
        map1.clear();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) a[i][j] = inf;
            a[i][i] = 0;
        }
        int k = 0;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            if(map1.find(u) == map1.end()) map1[u] = k++;
            if(map1.find(v) == map1.end()) map1[v] = k++;
            a[map1[u]][map1[v]] = 1; a[map1[v]][map1[u]] = 1;
        }
        cout << "Network " << (cas++) << ": ";
        floyd();
    }
    return 0;
}