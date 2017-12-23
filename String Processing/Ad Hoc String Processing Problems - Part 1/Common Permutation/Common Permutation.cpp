#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a, b;
    int counter[30];
    int val[30];
    while(cin.peek() != EOF){
        getline(cin, a); getline(cin, b);
        memset(counter, 0, sizeof counter); memset(val, 0, sizeof val);
        for(int i=0; i<a.size(); i++) counter[a[i]-'a']++;
        for(int i=0; i<b.size(); i++) val[b[i]-'a']++;
        string ans;
        for(int i=0; i<26; i++){
            ans += string(min(val[i], counter[i]), (char)(i+'a'));
        }
        cout << ans << "\n";
    }
    return 0;
}