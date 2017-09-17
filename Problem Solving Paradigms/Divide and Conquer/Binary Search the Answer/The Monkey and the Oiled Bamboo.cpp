#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int n, m, ans, sum, k, flag;
vi a;

void bs(){
    int lo = 0;
    int hi = 1000000000;
    int mid;
    while(lo < hi){
        flag = 0;
        mid = lo + (hi-lo)/2;
        k  = mid;
        for(int i=0; i<n; i++){
            if(a[i+1] - a[i] > k) {
                flag = 1; break;
            }
            if(a[i+1] - a[i] == k) k--;
        }
        if(flag) lo = mid+1;
        else hi = mid;
    }
    ans = lo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        cout << "Case " << cas << ": ";
        cin >> n;
        a.resize(n+1); a[0] = 0;
        for(int i=1; i<=n; i++) cin >> a[i];
        bs();
        cout << ans << "\n";
    }
    return 0;
}
