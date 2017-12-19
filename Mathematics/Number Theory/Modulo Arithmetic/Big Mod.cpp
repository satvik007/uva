#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef unsigned long long ull;

int phi[2000005], depth[2000005], sum[2000005];

int ipow(int base, int exp, int modulo){
    int result = 1; base %= modulo;
    while (exp){
        if (exp & 1)
            result = (result * base) % modulo;
        exp >>= 1;
        base = (base * base) % modulo;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int a, b, c;
    while(cin >> a >> b >> c){
        cout << ipow(a, b, c) << "\n";
    }
    return 0;
}