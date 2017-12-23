#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m, tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i=0; i<m; i++){
            for(int j=1; j<=n; j++){
                for(int k=0; k<j; k++) cout << j; cout << "\n";
            }
            for(int j=n-1; j>=1; j--){
                for(int k=0; k<j; k++) cout << j; cout << "\n";
            }
            if(i != m-1) cout << "\n";
        }
        if(tc != 0) cout << "\n";
    }
    return 0;
}