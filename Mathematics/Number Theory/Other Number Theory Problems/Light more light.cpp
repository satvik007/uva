#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef vector <int> vi;

long n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> n, n){
        long res = sqrt(n);
        cout << (res * res == n ? "yes\n" : "no\n");
    }
    return 0;
}