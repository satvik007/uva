#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef unsigned long long ull;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc; cin >> tc;
    vector <ull> fac(21);
    fac[0] = 1;
    ull res = 1;
    for(int i=1; i<=20; i++){
        res *= i;
        fac[i] = res;
    }
    for(int cas = 1; cas <= tc; cas++){
        string a; cin >> a;
        cout << "Data set " << cas << ": ";
        res = 1;
        int data[30]; memset(data, 0, sizeof data);
        for(int i=0; i<a.size(); i++) data[a[i]-'A']++;
        for(int i=0; i<26; i++) res *= fac[data[i]];
        cout << fac[a.size()] / res << "\n";
    }
    return 0;
}