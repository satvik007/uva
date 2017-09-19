#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef long long ll;

int n, m;
vi a(10005), b(10005);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cas = 1;
    while(cin >> n >> m, n||m){
        cout << "Case " << cas << ": ";
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<m; i++) cin >> b[i];
        if(n <= m) {
            cout << "0\n";
        }
        else{
            cout << (n - m) << " " << (*min_element(a.begin(), a.begin()+n)) << "\n";
        }
        cas++;
    }
    return 0;
}
