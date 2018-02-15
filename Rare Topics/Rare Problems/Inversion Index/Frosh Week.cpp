#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

ll n, a[1000010], b[1000010];

ll merge(int left, int right){
    for(int i=left; i<=right; i++) b[i] = a[i];
    int mid = (left + right)/2;
    int u = left, v = mid + 1;
    int k = left;
    ll res = 0;
    while(u != mid + 1 && v != right + 1){
        if(b[u] <= b[v]){
            a[k++] = b[u++];
        }else{
            res += (v - k);
            a[k++] = b[v++];
        }
    }
    while(u != mid + 1){
        a[k++] = b[u++];
    }
    while(v != right+1){
        a[k++] = b[v++];
    }
    return res;
}

ll inverse(int left, int right){
    ll res = 0;
    if(left < right){
        int mid = (left + right)/2;
        res += inverse(left, mid);
        res += inverse(mid + 1, right);
        res += merge(left, right);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n){
        for(int i=0; i<n; i++)
            cin >> a[i];
        ll ans = inverse(0, n-1);
        cout << ans << "\n";
    }
    return 0;
}