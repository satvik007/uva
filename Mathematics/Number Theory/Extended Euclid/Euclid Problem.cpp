#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

long a, b;

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
    while(cin >> a >> b){
        long d, x1, y1;
        extendedEuclid(a, b, d, x1, y1);
        cout << x1 << " " << y1 << " " << d << "\n";
    }
    return 0;
}