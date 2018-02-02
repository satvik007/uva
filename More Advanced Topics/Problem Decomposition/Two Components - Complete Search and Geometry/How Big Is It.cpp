#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

#define sq(x) ((x) * (x))

int n;
double a[10];

double solve(){
    double b[10];
    b[0] = a[0];
    double x, y, tx, ty;
    for(int i=1; i<n; i++){
        tx = a[i];
        for(int j=0; j<i; j++){
            x = b[j] + sqrt(sq(a[i] + a[j]) - sq(a[j] - a[i]));
            tx = max(tx, x);
        }
        b[i] = tx;
    }
    tx = -1;
    for(int i=0; i<n; i++){
        tx = max(tx, b[i] + a[i]);
    }
    return tx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    cout << fixed << setprecision(3);
    while(tc--){
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        double ans = LONG_MAX;
        do{
            ans = min(ans, solve());
        }while(next_permutation(a, a+n));
        cout << ans << "\n";
    }
    return 0;
}
