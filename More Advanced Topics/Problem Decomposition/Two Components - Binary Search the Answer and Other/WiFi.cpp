#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, m;
int a[100010];

bool solve(int mid){
    int cnt = 0, pos;
    for(int i=0; i<m; i++){
        pos = a[i] + mid;
        cnt++;
        while(abs(pos - a[i]) <= mid && i < m) i++;
        i--;
    }
    return cnt <= n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    cout << fixed << setprecision(1);
    while(tc--){
        cin >> n >> m;
        for(int i=0; i<m; i++){
            cin >> a[i]; a[i] *= 10;
        }
        sort(a, a+m);
        int ans = 10000000;
        int lo = 0, mid, hi = ans;
        while(lo <= hi){
            mid = lo + (hi - lo)/2;
            if(solve(mid)) hi = mid - 1, ans = min(ans, mid);
            else lo = mid + 1;
        }
        cout << (ans/10.0) << "\n";
    }
    return 0;
}