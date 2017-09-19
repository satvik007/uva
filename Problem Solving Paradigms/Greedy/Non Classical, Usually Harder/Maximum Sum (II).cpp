#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int n, m;
vi a;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        a.resize(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int index = n;
        for(int i=0; i<n; i++){
            if(a[i] != 0){
                cout << a[i];
                index = i;
                break;
            }
        }
        for(int i=index+1; i<n; i++){
            if(a[i] != 0) cout << " " << a[i];
        }
        if(index == n) cout << "0";
        cout << "\n";

    }
    return 0;
}
