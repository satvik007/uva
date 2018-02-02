#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll a[60], b[15];
int n, t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> t, n||t){
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<t; i++)
            cin >> b[i];
        ll max1, min1;
        ll res1, res2, res, lcm;
        for(int m = 0; m<t; m++){
            max1 = -1; min1 = LONG_MAX;
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    for(int k=j+1; k<n; k++){
                        for(int l=k+1; l<n; l++){
                            res1 = a[i] * a[j] / __gcd(a[i], a[j]);
                            res2 = a[k] * a[l] / __gcd(a[k], a[l]);
                            lcm = res1 * res2 / __gcd(res1, res2);
                            //cout << a[i] << " " << a[j] << " " << a[k] << " " << a[l] << endl;
                            ll cur = b[m]/lcm;
                            if(cur * lcm == b[m]){
                                max1 = min1 = b[m]; break;
                            }
                            max1 = max(max1, cur * lcm);
                            min1 = min(min1, (cur+1) * lcm);
                        }
                    }
                }
            }
            cout << max1 << " " << min1 << "\n";
        }

    }
    return 0;
}