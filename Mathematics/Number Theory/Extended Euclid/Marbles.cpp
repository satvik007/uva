#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

long x, y;
long c1, n1, c2, n2, n;

void extendedEuclid(long a, long b, long &d, long &x, long &y){
    if(b == 0){
        d = a; x = 1; y = 0; return;
    }
    long x1, y1;
    extendedEuclid(b, a % b, d, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}
bool solve(){
    long gcd, m1, m2;
    extendedEuclid(n1, n2, gcd, m1, m2);
    if(n % gcd != 0) return false;
    m1 *= n / gcd; m2 *= n / gcd;
    n1 /= gcd; n2 /= gcd;
    long c = ceil(-(double)m1/n2), f = floor((double)m2/n1);
    if(c > f) return false;
    long cost = c1 * n2 - c2 * n1;
    if(cost * c < cost * f){
        x = m1 + c * n2; y = m2 - c * n1;
    }else{
        x = m1 + f * n2; y = m2 - f * n1;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        cin >> c1 >> n1 >> c2 >> n2;
        if(solve()) cout << x << " " << y << "\n";
        else cout << "failed\n";
    }
    return 0;
}