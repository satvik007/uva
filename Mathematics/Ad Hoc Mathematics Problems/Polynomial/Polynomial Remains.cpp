#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

int n, k;
vi a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> k, n >= 0){
        a.resize(n+5);
        for(int i=n; i>=0; i--) cin >> a[i];
        for(int i = 0; i <= n-k; i++) {
            a[i+k] -= a[i];
            a[i] = 0;
        }
        int i = 0;
        while(a[i] == 0 && i <= n) i++;
        if(n < i)   cout << "0\n";
        else{
            for(int j = n; j >= i; j--) {
                if(j != n)  cout << " ";
                cout << a[j];
            }
            cout << "\n";
        }
    }
    return 0;
}
