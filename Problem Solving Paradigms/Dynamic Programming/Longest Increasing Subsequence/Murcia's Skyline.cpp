#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    int n;
    vi a, b, c;
    for(int cas=1; cas<=t; cas++){
        cin >> n;
        a.resize(n); c.resize(n);
        b.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=0; i<n; i++){
            c[i] = b[i];
            for(int j=0; j<i; j++){
                if(a[j] < a[i]) {
                    c[i] = max(c[i], c[j]+b[i]);
                }
            }
        }
        ll max1 = *max_element(c.begin(), c.end());
        for(int i=0; i<n; i++){
            c[i] = b[i];
            for(int j=0; j<i; j++){
                if(a[j] > a[i]) {
                    c[i] = max(c[i], c[j]+b[i]);
                }
            }
        }
        ll max2 = *max_element(c.begin(), c.end());
        cout << "Case " << cas << ". ";
        if(max1 >= max2) cout << "Increasing ("<< max1 << "). Decreasing (" << max2 << ").\n";
        else cout << "Decreasing ("<< max2 << "). Increasing (" << max1 << ").\n";
    }
}
