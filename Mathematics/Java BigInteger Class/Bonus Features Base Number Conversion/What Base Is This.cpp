#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;

ll base(string nm, int base) {
    ll ret = 0;
    ll mult = 1;
    for(int i = nm.size() - 1; i >= 0; i--) {
        if(isdigit(nm[i])) {
            if(nm[i]-48 >= base) return -1;
            ret += (nm[i] - 48) * mult;
        }
        else{
            if(nm[i]-65+10 >= base) return -1;
            ret += (nm[i] - 65 + 10) * mult;
        }
        mult *= base;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string a, b;
    while(cin >> a >> b){
        int flag = 0;
        pair <int, int> ans;
        for(int i=2; i<37 && !flag; i++){
            for(int j=2; j<37; j++){
                ll c1 = base(a, i);
                //ll c2 = base(b, j);
                if(c1 == base(b, j) && c1 != -1){
                    flag = 1; ans = {i, j};
                    break;
                }
            }
        }
        if(!flag) cout << a << " is not equal to " << b << " in any base 2..36\n";
        else cout << a << " (base " << ans.first << ") = " << b <<
        " (base " << ans.second << ")\n";
    }
    return 0;
}