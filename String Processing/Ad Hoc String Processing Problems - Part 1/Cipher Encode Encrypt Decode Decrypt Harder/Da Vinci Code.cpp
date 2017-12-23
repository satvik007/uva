#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector <ll> fib(80);
    fib[0] = 1; fib[1] = 2;
    for(int i=2; i<80; i++) fib[i] = fib[i-1] + fib[i-2];
    int n, tc; cin >> tc;
    vi a; string b;
    int used[100];
    while(tc--){
        cin >> n; a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        cin.ignore(); getline(cin, b);
        for(int i=0; i<b.size(); i++){
            if(b[i] < 'A' || b[i] > 'Z') {
                b.erase(b.begin()+i); i--;
            }
        }
        string ans; memset(used, 0, sizeof used);
        for(int i=0; i<n; i++){
            used[lower_bound(fib.begin(), fib.end(), a[i]) - fib.begin()] = 1;
        }
        int val = lower_bound(fib.begin(), fib.end(), *max_element(a.begin(), a.end())) - fib.begin();
        ans.resize(1 + val);
        for(int i=0; i<n; i++){
            int current = lower_bound(fib.begin(), fib.end(), a[i]) - fib.begin();
            ans[current] = b[i];
        }
        for(int i=0; i<ans.size(); i++){
            if(ans[i]<'A' || ans[i] > 'Z') ans[i] = ' ';
        }
        cout << ans << "\n";
    }

    return 0;
}