#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

vi a;
int max1, n, counter, k;

void jeffDean(int u, int mask){
    if(max1 || u > k) return;
    if(u == k) max1 = 1;
    for(int i=0; i<n; i++){
        if(!(mask & (1<<i))) jeffDean(u+a[i], mask|(1<<i));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> k >> n;
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        max1 = 0;
        jeffDean(0, 0);
        cout << (max1 ? "YES\n": "NO\n");
    }
    return 0;
}
