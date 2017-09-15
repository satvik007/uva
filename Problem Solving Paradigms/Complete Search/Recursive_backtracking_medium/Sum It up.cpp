
#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

vi a;
vi ans;
int max1, n, counter, k;

void jeffDean(int u, int mask, int r){
    if(u > k) return;
    if(u == k){
        ans.push_back(mask);
        return;
    }
    for(int i=r; i<n; i++){
        if(!(mask & (1<<i))) {
            jeffDean(u+a[i], mask|(1<<i), i+1);
            int last = a[i];
            while(a[i] == last) i++; i--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> k >> n, k||n){
        a.resize(n); ans.clear();
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        cout << "Sums of " << k << ":\n";
        jeffDean(0, 0, 0);
        sort(ans.begin(), ans.end(), greater<int> ());
        if(ans.empty()) cout << "NONE\n";
        else{
            for(auto el:ans){
                int k = 0;
                for(int j=n-1; j>=0; j--){
                    if(el & (1<<j)) {
                        if(k == 0) cout << a[j];
                        else cout << "+" << a[j];
                        k++;
                    }
                }
                cout << "\n";
            }
        }
    }
    return 0;
}