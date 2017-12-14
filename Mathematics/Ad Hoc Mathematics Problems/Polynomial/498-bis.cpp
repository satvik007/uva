#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

vi num;
int x, n;

void func(){
    ll ans = 0, res = 1;
    for(int i=n-2; i>=0; i--){
        ans += (n - 1 - i) *  res * num[i];
        res *= x;
    }
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a, b;
    while(cin.peek() != '\n' && cin.peek() != EOF){
        cin >> x; cin.ignore();
        getline(cin, a);
        stringstream cin1(a);
        num.clear();
        int u;
        while(cin1 >> u) num.push_back(u);
        n = (int)num.size();
        func();
    }
    return 0;
}
