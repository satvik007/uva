#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int n, tc, counter[15];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> tc;
    string a;
    while(tc--){
        memset(counter, 0, sizeof counter);
        cin >> n;
        for(int i=1; i<=n; i++){
            a = to_string(i);
            for(int i=0; i<a.size(); i++){
                counter[a[i]-'0']++;
            }
        }
        for(int i=0; i<9; i++){
            cout << counter[i] << " ";
        }
        cout << counter[9] << "\n";
    }
    return 0;
}