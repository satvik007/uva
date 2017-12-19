#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef unsigned long long ull;

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
    string a;
    int mod = 131071;
    while(cin.peek() != EOF){
        string b; a.clear();
        while(true){
            cin >> b;
            a += b;
            if(b[b.size()-1] == '#') break;
        } cin.ignore();
        int res = 1; int sum = 0;
        for(int i=1; i<a.size(); i++){
            sum = (sum + res * (a[a.size()-i-1] - '0')) % mod;
            res = (res << 1) % mod;
        }
        if(sum == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}