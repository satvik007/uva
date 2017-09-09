#include <bits/stdc++.h>
#define epsilon 1e-9
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m, q, temp, min;
    vi a;
    int index;
    int cas = 1;
    while(cin >> n, n){
        cout << "Case " << cas << ":\n";
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        cin >> q;
        while(q--){
            cin >> temp;
            min = INT_MIN;
            for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(abs(a[i]+a[j] - temp) < abs(min - temp)) min = a[i]+a[j];
                }
            }
            cout << "Closest sum to " << temp << " is " << min << ".\n";
        }

		cas++;
    }
    return 0;
}
