#include <bits/stdc++.h>
#define epsilon 1e-9
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, counter, count;
    cin >> t;
    vi a;
    while(t--){
        cin >> n;
        a.resize(n);
        count = 0;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=1; i<n; i++){
            counter = 0;
            for(int j=0; j<i; j++){
                if(a[j] <= a[i]) counter++;
            }
            count += counter;
        }
        cout << count << "\n";
    }
    return 0;
}
