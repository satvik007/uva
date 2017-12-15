#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string convert(int res, int base){
    string ans;
    while(res){
        ans.push_back((char)(res % base + '0'));
        res /= base;
    }
    if(ans.empty()) ans += '0';
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int base;
    string a, b;
    while(cin >> base, base){
        cin >> a >> b;
        ll mult = 1, res=0, n;
        for(int i=b.size()-1; i>=0; i--){
            res += mult * (b[i]-'0');
            mult *= base;
        }
        n = res;
        //cout << n << "\n";
        mult = 1; res = 0;
        for(int i=a.size()-1; i>=0; i--){
            res = (res + mult * (a[i]-'0')) % n;
            mult = (mult * base) % n;
        }
        string ans = convert(res, base);
        cout << ans << "\n";
    }
    return 0;
}