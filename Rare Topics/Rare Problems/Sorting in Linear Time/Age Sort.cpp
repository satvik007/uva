#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, a[105];
    while(cin >> n, n){
        int u; memset(a, 0, sizeof a);
        for(int i=0; i<n; i++){
            cin >> u; a[u]++;
        }
        int flag = 0;
        for(int i=0; i<=100; i++){
            while(a[i]){
                if(flag) cout << " " << i;
                else cout << i;
                flag = 1;
                a[i]--;
            }
        }
        cout << "\n";
    }
    return 0;
}