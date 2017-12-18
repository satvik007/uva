#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc, u;
    string line;
    cin >> tc; cin.ignore();
    while(tc--){
        vi a;
        getline(cin, line);
        stringstream take(line);
        while(take >> u) a.push_back(u);
        int max1 = 1;
        for(int i=0; i<a.size(); i++){
            for(int j=i+1; j<a.size(); j++){
                max1 = max(max1, __gcd(a[i], a[j]));
            }
        }
        cout << max1 << "\n";
    }
    return 0;
}