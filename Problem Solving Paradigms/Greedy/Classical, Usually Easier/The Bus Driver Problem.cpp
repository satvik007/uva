#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int t, n, counter, d, r;
ll sum = 0;
vi a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n >> d >> r, n){
        a.resize(n);
        b.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int j=0; j<n; j++) cin >> b[j];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        counter = 0;
        for(int i=0; i<n; i++){
            counter += max(0, (a[i]+b[i] - d)*r);
        }
        cout << counter << endl;
    }
}
