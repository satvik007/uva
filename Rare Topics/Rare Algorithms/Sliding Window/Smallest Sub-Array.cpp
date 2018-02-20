#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
#define maxn 1000010

int tc, n, m, k;
int a[maxn];
unordered_map <int, int> map1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    int cas = 1;
    while(tc--){
        cin >> n >> m >> k;
        cout << "Case " << cas++ << ": ";
        a[0] = 1; a[1] = 2; a[2] = 3;
        for(int i=3; i<n; i++){
            a[i] = (a[i-3]+a[i-2]+a[i-1]) % m + 1;
        }
        int l = 0, r = 1;
        int ans = 2*n;
        map1.clear();
        if(a[l] <= k) map1[a[l]] = 1;
        while(r < n){
            if(l == r){
                if(a[r] <= k) map1[a[r]] = 1;
                r++;
                continue;
            }
            if(r - l > ans){
                if(map1.count(a[l])){
                    if(map1[a[l]] == 1) map1.erase(a[l]);
                    else map1[a[l]]--;
                }
                l++;
                continue;
            }
            if(map1.size() == k){
                while(map1.size() == k && l <= r){
                    ans = min(ans, r - l);
                    if(map1.count(a[l])){
                        if(map1[a[l]] == 1) map1.erase(a[l]);
                        else map1[a[l]]--;
                    }
                    l++;
                }
            }else{
                while(map1.size() != k && r < n){
                    if(a[r] <= k){
                        if(map1.count(a[r])) map1[a[r]]++;
                        else map1[a[r]] = 1;
                    }
                    r++;
                }
            }
        }
        if(map1.size() == k){
            while(map1.size() == k && l <= r){
                ans = min(ans, r - l);
                if(map1.count(a[l])){
                    if(map1[a[l]] == 1) map1.erase(a[l]);
                    else map1[a[l]]--;
                }
                l++;
            }
        }
        if(ans == 2*n) cout << "sequence nai\n";
        else cout << ans << "\n";
    }
    return 0;
}