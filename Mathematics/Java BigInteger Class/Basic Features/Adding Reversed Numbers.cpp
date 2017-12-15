#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

string add(string a, string b){
    int n = max(a.size(), b.size());
    int carry=0, c1, c2, s;
    string ans;
    for(int i=0; i<n; i++){
        if(i >= a.size()) c1 = 0;
        else c1 = (a[a.size()-i-1]-'0');
        if(i >= b.size()) c2 = 0;
        else c2 = (b[b.size()-i-1]-'0');
        s = c1 + c2 + carry;
        carry = s / 10;
        s = s % 10;
        ans.push_back((char)(s+'0'));
    }
    if(carry != 0) ans.push_back((char)(carry+'0'));
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    while(n--){
        string a, b;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c = add(a, b);
        int flag = 0;
        for(int i=0; i<c.size(); i++){
            if(c[i] != '0') flag = 1;
            if(flag) cout << c[i];
        }
        cout << endl;
    }

    return 0;
}