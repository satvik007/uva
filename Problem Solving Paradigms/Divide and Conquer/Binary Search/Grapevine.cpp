#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m, q, u, v, index, len, hi, curr, row, col, max1, current;
    vector <vi> a;
    vector <pair<int, int>> b;
    while(cin >> n >> m, n||m){
        a.resize(n);
        for(int i=0; i<n; i++){
            a[i].resize(m);
            for(int j=0; j<m; j++){
                cin >> a[i][j];
            }
        }
        cin >> q;
        len = 0; hi = 0;
        while(q--){
        	b.clear();
            cin >> u >> v;
            for(int i=0; i<n; i++){
                b.push_back({lower_bound(a[i].begin(), a[i].end(), u)-a[i].begin(), (--upper_bound(a[i].begin(), a[i].end(), v)) - a[i].begin()});
            }
            max1 = 0;
            for(int i=0; i<b.size(); i++){
                for(int j=i; j<b.size(); j++){
                	if(b[j].second < b[i].first) break;
                    current = min(j-i ,b[j].second - b[i].first)+1;
                    if(current > max1) max1 = current;
                }
            }
            cout << max1 << "\n";
        }
        cout << "-\n";
    }
    return 0;
}
