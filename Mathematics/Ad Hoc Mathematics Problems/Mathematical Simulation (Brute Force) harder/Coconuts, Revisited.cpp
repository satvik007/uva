#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll n;

int func(int t){
    ll left = n;
    int res = 1;
    for(int i=0; i<t; i++){
        if((left % t) != 1){res = 0; break;}
        left = (left)*(t-1)/t;
    }
    if(left % t != 0) res = 0;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n >= 0){
        cout << n << " coconuts, ";
        int flag = 0, ans;
        for(int t=10; t>1; t--){
            if(func(t)){
                ans = t; flag = 1; break;
            }
        }
        if(flag) cout << ans << " people and 1 monkey\n";
        else cout << "no solution\n";
    }
    return 0;
}