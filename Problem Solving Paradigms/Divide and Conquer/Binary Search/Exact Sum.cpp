#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, k, index, left, right, ans;
    vi a;
    auto it = a.begin();
    while(cin >> n){
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        cin >> k;
        sort(a.begin(), a.end());
        index = (lower_bound(a.begin(), a.end(), k/2)) - a.begin();
        left = 0; right = n-1; ans = 0;
        for(int i=index; i<n; i++){
            it = lower_bound(a.begin(), a.begin()+index, k - a[i]);
            if(it != a.end() && *it == k - a[i] && i != it - a.begin()){
                ans = i; break;
            }
        }
        cout << "Peter should buy books whose prices are " 
             << min(a[ans], k - a[ans]) << " and " <<  max(a[ans], k - a[ans]) << ".\n\n";
    }

    return 0;
}
