#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;
#define eps 1e-7

string num1, num2;

ll base(string nm, int base) {
    ll ret = 0;
    ll mult = 1;
    for(int i = nm.size() - 1; i >= 0; i--) {
        if(isdigit(nm[i])) {
            ret += (nm[i] - 48) * mult;
        }
        else ret += (nm[i] - 65 + 10) * mult;
        mult *= base;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string num;
    int base1, base2;
    while(cin >> num >> base1 >> base2) {
        ll val = base(num, base1);
        if(val == 0) {
            cout << setw(7) << val << "\n";
            continue;
        }
        string ans;
        int digits = floor(eps + 1 + (log(val) / log(base2)));
        for(int i = digits - 1; i >= 0; i--) {
            ll den = pow(base2, i);
            if(val < den) {
                ans.push_back(48);
                continue;
            }
            ll digit = val / den;
            if(digit > 9) {
                ans.push_back(65 + digit - 10);
            }
            else ans.push_back(digit + 48);
            val = val % den;
        }
        if(ans.size() > 7) cout << "  ERROR\n";
        else cout << setw(7) << ans << "\n";
    }
}