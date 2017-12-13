#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a;
    cout << fixed;
    while(cin >> a){
        int len = a.size() + 1;
        double left, right;
        double n = stod(a);
        while(true){
            left = log(n)/log(2.0) + len * log(10.0) / log (2.0);
            right = log(n+1) / log(2.0) + len * log(10.0) / log(2.0);
            if((int)left < (int)right) break;
            len++;
        }
        cout << (int)ceil(left) << "\n";
    }
    return 0;
}
