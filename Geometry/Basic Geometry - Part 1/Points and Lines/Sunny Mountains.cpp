#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    cout << fixed << setprecision(2);
    while(tc--){
        int n; cin >> n;
        vector <pair <double, double>> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end());
        double ans = 0, height = 0;
        for(int i=n-2; i>=0; i--){
            if(a[i].second > height){
                ans += (a[i].second - height) * hypot((a[i].first - a[i+1].first)/(a[i].second - a[i+1].second), 1);
                height = a[i].second;
            }
        }
        cout << ans << "\n";
    }


    return 0;
}