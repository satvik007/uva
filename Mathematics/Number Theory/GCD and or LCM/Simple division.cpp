#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u;
    while(true){
        vi a;
        while(cin >> u, u) a.push_back(u);
        if(a.empty()) break;
        int res = a[1]-a[0];
        for(int i=1; i<a.size(); i++) a[i] -= a[0], res = gcd(res, a[i]);
        cout << abs(res) << "\n";
    }
    return 0;
}