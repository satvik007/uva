#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int f(int n) {
    if(n <= 1)
        return 1;
    if(n&1)
        return (f((n+1)/2)-1)*2;
    else
        return f(n/2)*2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n, n){
        cout << f(n) << "\n";
    }
    return 0;
}