#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    size_t n, m;
    int u, v;
    while(cin >> n >> m){
        vector <vii> a(m);
        vector <int> b;
        size_t size;
        for(int i=0; i<n; i++){
            cin >> size;
            b.resize(size);
            for(int j=0; j<size; j++) cin >> b[j];
            for(int j=0; j<size; j++){
                cin >> v;
                a[b[j]-1].push_back({i, v});
            }
        }
        cout << m << " " << n << "\n";
        for(int i=0; i<m; i++){
            cout << a[i].size();
            for(auto el:a[i]){
                cout << " " << el.first+1;
            }
            cout << "\n";
            for(int j=0; j<a[i].size(); j++){
                if(j!=0) cout << " ";
                cout << a[i][j].second;
            }
            cout << "\n";
        }
    }
    return 0;
}
