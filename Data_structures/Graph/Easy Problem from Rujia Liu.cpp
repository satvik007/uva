#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m;
    while(cin >> n >> m){
        unordered_map <int, vi> a;
        int temp;
        for(int i=0; i<n; i++){
            cin >> temp;
            a[temp].push_back(i+1);
        }
        int u, v;
        for(int i=0; i<m; i++){
            cin >> u >> v;
            if(a[v].size() < u) cout << "0\n";
            else cout << a[v][u-1] << "\n";
        }
    }
    return 0;
}
