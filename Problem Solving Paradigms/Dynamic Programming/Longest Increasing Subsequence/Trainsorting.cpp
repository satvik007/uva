#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int a[2005];
int b[2005];
int c[2005];
int d[2005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=n-1; i>=0; i--){
            b[i] = 1; c[i] = 1;
            for(int j=i+1; j<n; j++){
                if(a[i] < a[j]) b[i] = max(b[i], b[j]+1);
                else c[i] = max(c[i], c[j]+1);
            }
            ans = max(ans, b[i]+c[i]-1);
        }
        cout << ans << "\n";
    }
}
