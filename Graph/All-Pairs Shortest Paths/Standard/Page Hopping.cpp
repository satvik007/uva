#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define inf 100000000

int n, m;
int a[105][105];
map<int, int> map1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u, v;
    cout << fixed << setprecision(3);
    int cas = 1;
    while(cin >> u >> v, u||v){
        map1.clear();
        n = 0;
        if(map1.find(u) == map1.end()) map1[u] = n++;
        if(map1.find(v) == map1.end()) map1[v] = n++;
        for(int i=0; i<105; i++){
            for(int j=0; j<105; j++) a[i][j] = inf;
            a[i][i] = 0;
        }
        a[map1[u]][map1[v]] = 1;
        while(cin >> u >> v, u||v){
            if(map1.find(u) == map1.end()) map1[u] = n++;
            if(map1.find(v) == map1.end()) map1[v] = n++;
            a[map1[u]][map1[v]] = 1;
        }
        for(int k=0; k<n; k++)for(int i=0; i<n; i++) for(int j=0; j<n; j++)
                    a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
        int counter = 0;
        //for(int i=0; i<n; i++) { for(int j=0; j<n; j++) cout << a[i][j] << " ";cout << endl; }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) counter += a[i][j];
        }
        cout << "Case " << cas << ": average length between pages = "
             << (double)(counter)/(n*n-n) << " clicks\n";
        cas++;
    }
    return 0;
}
