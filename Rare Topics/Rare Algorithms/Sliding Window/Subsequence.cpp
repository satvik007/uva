#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn (int)1e6

int n, sum;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> sum){
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int l = 0, r = 0;
        int val = 0;
        int ans = INT_MAX;
        while(r < n && l < n){
            if(val >= sum){
                ans = min(ans, r - l);
                val -= a[l++];
            }else{
                val += a[r++];
            }
        }
        if(val >= sum){
            ans = min(ans, r - l);
        }
        val = 0;
        for(int i=n-1; i>=0; i--){
            val += a[i];
            if(val >= sum){
                ans = min(ans, n-i);
                break;
            }
        }
        if(ans == INT_MAX) ans = 0;
        cout << ans << "\n";
    }
    return 0;
}