#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

long a, b, a1, b1;

void extendedEuclid(long a, long b, long &d, long &x, long &y){
    if(b == 0){
        d = a; x = 1; y = 0; return;
    }
    long x1, y1;
    extendedEuclid(b, a % b, d, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    while(tc--){
        long x, y, d;
        cin >> a1 >> b1;
        a = floor((double)a1 / b1);
        b = ceil((double)a1 / b1);
        extendedEuclid(a, b, d, x, y);
        x *= a1/d; y *= a1/d;
        cout << x << " " << y << "\n";
    }
    return 0;
}