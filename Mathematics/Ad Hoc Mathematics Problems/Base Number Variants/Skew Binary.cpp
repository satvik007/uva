#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vi;

string a;
void convert(){
    ll last = 1;
    ll res = 0;
    for(int i=0; i<a.size(); i++){
        //cout << last << endl;
        res += last * (a[a.size()-i-1]-'0');
        last = (last + 1) * 2 - 1;
    }
    cout << res << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(cin >> a){
        if(a == "0") break;
        convert();
    }
    return 0;
}
